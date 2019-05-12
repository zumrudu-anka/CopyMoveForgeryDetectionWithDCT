import cv2
import numpy as np
import scipy.ndimage
from operator import itemgetter
import math
from tkinter import *
from tkinter import messagebox
from tkinter import filedialog
from tkinter import ttk
from MyFunctions import *

Q_90=[
		[3,2,2,3,5,8,10,12],
		[2,2,3,4,5,12,12,11],
		[3,3,3,5,8,11,14,11],
		[3,3,4,6,10,17,16,12],
		[4,4,7,11,14,22,21,15],
		[5,7,11,13,16,12,23,18],
		[10,13,16,17,21,24,24,21],
		[14,18,19,20,22,20,20,20]
	]

Q_50=[
		[16,11,10,16,24,40,51,61],
		[12,12,14,19,26,58,60,55],
		[14,13,16,24,40,57,69,56],
		[14,17,22,29,51,87,80,62],
		[18,22,37,56,68,109,103,77],
		[24,35,55,64,81,104,113,92],
		[49,64,78,87,103,121,120,101],
		[72,92,95,98,112,100,103,99]
	]

Q_10=[
		[80,60,50,80,120,200,255,255],
		[55,60,70,95,130,255,255,255],
		[70,65,80,120,200,255,255,255],
		[70,85,110,145,255,255,255,255],
		[90,110,185,255,255,255,255,255],
		[120,175,255,255,255,255,255,255],
		[245,255,255,255,255,255,255,255],
		[255,255,255,255,255,255,255,255]
	]

Q_CL=[
		[16,11,10,16,24,40,51,61],
		[12,12,14,19,26,58,60,55],
		[14,13,16,24,40,57,69,56],
		[14,17,22,29,51,87,80,62],
		[18,22,37,56,68,109,103,77],
		[24,35,55,64,81,104,113,92],
		[49,64,78,87,103,121,120,101],
		[72,92,95,98,112,100,103,99]
	]

def OpenShowImage():
	global img,firstimage,first_image_label
	filename=filedialog.askopenfilename(initialdir = "../Forged Images/",title = "Open File",filetypes = (("png files","*.png"),("bmp files","*.bmp"),("jpeg files","*.jpg"),("All Files","*.*")))
	firstimage=PhotoImage(file='{}'.format(filename))
	first_image_label=Label(leftframe,image=firstimage)
	first_image_label.pack()
	img=cv2.imread('{}'.format(filename),0)

def AccuracyTest():
	filename = filedialog.askopenfilename(initialdir = "../Forged Images/",title ="Open File",filetypes = (("png files","*.png"),("bmp files","*.bmp"),("jpeg files","*.jpg"),("All Files","*.*")))
	img_for_accuracy = cv2.imread('{}'.format(filename),0)
	dp=0
	yp=0
	yn=0
	for i in range(height):
		for j in range(width):
			if(img_for_accuracy[i][j]==0 and img2[i][j] == 255):
				yp+=1
			elif(img_for_accuracy[i][j]==255 and img2[i][j] == 255):
				dp+=1
			elif(img_for_accuracy[i][j]==255 and img2[i][j] == 0):
				yn+=1
	precision = dp / (dp + yp)
	recall = dp / (dp + yn)
	f1 = 2 * (precision * recall) / (precision + recall)
	messagebox.showinfo("Accuracy Result",f1)

def GetQuantizationMatrix(size,mainsize):
	for i in range (0,size):
		for j in range(0,size):
			quantization_matrix[i][j]=(pow(2,size-2))
	if (size != 2):
		GetQuantizationMatrix(size-1,mainsize)

def MakeDCT():
	global height,width
	height, width = img.shape
	vis0=np.zeros((height,width),np.float32)
	vis0[:height,:width]=img
	global quantization_matrix
	quantization_matrix=[[] for i in range(0,8)]
	for i in quantization_matrix:
		for j in range(0,8):
			i.append(0)
	GetQuantizationMatrix(8,8)
	global diagonaled_array
	diagonaled_array=[[] for i in range((height-7)*(width-7))]
	count=0
	for i in range (0,height-7):
		for j in range(0,width-7):
			####		Make Quantization With Q_CL Matrix 		  ####
			if(quantization_matrix_selection_box.get() == "Q_CL"):
				vis1 = cv2.dct(vis0[i:i+8,j:j+8])
				for k in range(0,8):
					for t in range(0,8):
						vis1[k][t] = GetMinDistValue((vis1[k][t] / Q_CL[k][t]))
				vis1 = getdiagonalarray(vis1,8,8)
			
			####		Make Quantization With Q_90 Matrix 		  ####
			elif(quantization_matrix_selection_box.get() == "Q_90"):
				vis1 = cv2.dct(vis0[i:i+8,j:j+8])
				for k in range(0,8):
					for t in range(0,8):
						vis1[k][t] = GetMinDistValue((vis1[k][t] / Q_90[k][t]))
				vis1 = getdiagonalarray(vis1,8,8)
			
			####		Make Quantization With Q_50 Matrix 		  ####
			elif(quantization_matrix_selection_box.get() == "Q_50"):
				vis1 = cv2.dct(vis0[i:i+8,j:j+8])
				for k in range(0,8):
					for t in range(0,8):
						vis1[k][t] = GetMinDistValue((vis1[k][t] / Q_50[k][t]))
				vis1 = getdiagonalarray(vis1,8,8)

			####		Make Quantization With Q_10 Matrix 		  ####
			elif(quantization_matrix_selection_box.get() == "Q_10"):
				vis1 = cv2.dct(vis0[i:i+8,j:j+8])
				for k in range(0,8):
					for t in range(0,8):
						vis1[k][t] = GetMinDistValue((vis1[k][t] / Q_10[k][t]))
				vis1 = getdiagonalarray(vis1,8,8)
			
			####		Make Quantization With Divide By 16 		  ####
			elif(quantization_matrix_selection_box.get() == "Divide by 16"):
				vis1 = cv2.dct(vis0[i:i+8,j:j+8])
				for k in range(0,8):
					for t in range(0,8):
						vis1[k][t] = GetMinDistValue((vis1[k][t] / 16))
				vis1 = getdiagonalarray(vis1,8,8)

			##############    Not Make Quantization 	##############
			elif(quantization_matrix_selection_box.get() == "Not Selected"):
				vis1 = getdiagonalarray(cv2.dct(vis0[i:i+8,j:j+8]), 8, 8)
			
			####	Make Quantization With Quantization Matrix    ####
			elif(quantization_matrix_selection_box.get() == "QTable in Article"):
				vis1 = cv2.dct(vis0[i:i+8,j:j+8])
				for k in range(0,8):
					for t in range(0,8):
						vis1[k][t] = GetMinDistValue(vis1[k][t] / quantization_matrix[k][t])
				vis1 = getdiagonalarray(vis1,8,8)

			diagonaled_array[count].append(vis1)
			diagonaled_array[count].append([i,j])
			count+=1
	messagebox.showinfo("Success","DCT Dönüşüm Tamamlandı")
number_of_vector_to_compare=10
max_euclidean_distance=1.0
threshold_distance_for_similar_blocks=5
min_count_for_similar_shift_vectors=10

def TryToDetectForgery():
	global hough_space,img2,result_image,result_image_label
	hough_space=[]

	diagonaled_array.sort(key=itemgetter(0))

	for i in range(0,len(diagonaled_array) - number_of_vector_to_compare + 1):
		toplam = 0.0
		for j in range(i + 1,i + number_of_vector_to_compare):
			for k in range(0, 15):
				toplam += pow(( diagonaled_array[i][0][k] - diagonaled_array[j][0][k]), 2)
			if(math.sqrt(toplam) < max_euclidean_distance):
				if(math.sqrt(pow((diagonaled_array[i][1][0]-diagonaled_array[j][1][0]),2) + pow((diagonaled_array[i][1][1]-diagonaled_array[j][1][1]),2)) > threshold_distance_for_similar_blocks):
					hough_space.append(diagonaled_array[i][1][0])
					hough_space.append(diagonaled_array[i][1][1])
					hough_space.append(diagonaled_array[j][1][0])
					hough_space.append(diagonaled_array[j][1][1])
					hough_space.append([abs(diagonaled_array[i][1][0]-diagonaled_array[j][1][0]),abs(diagonaled_array[i][1][1]-diagonaled_array[j][1][1])])

	img2 = np.zeros((height,width,1),np.uint8)

	for i in range(4,len(hough_space),5):
		if(hough_space.count(hough_space[i]) > min_count_for_similar_shift_vectors):
			for j in range(0,8):
				for k in range(0,8):
					img2[hough_space[i-4]+j,hough_space[i-3]+k,0]=255
					img2[hough_space[i-2]+j,hough_space[i-1]+k,0]=255

	filename = filedialog.asksaveasfilename(initialdir = "../Forged Images/",title = "Save File",filetypes = (("png files","*.png"),("bmp files","*.bmp"),("jpeg files","*.jpg"),("All Files","*.*")))
	cv2.imwrite('{}'.format(filename),img2)
	result_image=PhotoImage(file='{}'.format(filename))
	result_image_label=Label(rightframe,image=result_image)
	result_image_label.pack()


def GetNumberOfVectorToCompare():
	global number_of_vector_to_compare
	number_of_vector_to_compare=int(number_of_vector_to_compare_spin.get())

def GetMaxEuclideanDistance():
	global max_euclidean_distance
	max_euclidean_distance=float(maximum_Euclidean_distance_spin.get())

def GetThresholdDistanceForSimilarBlocks():
	global threshold_distance_for_similar_blocks
	threshold_distance_for_similar_blocks=int(threshold_distance_for_similar_blocks_spin.get())

def GetMinCountForSimilarShiftVectors():
	global min_count_for_similar_shift_vectors
	min_count_for_similar_shift_vectors=int(min_count_for_similar_shift_vectors_spin.get())

root=Tk()
root.geometry("800x325")
root.title("Copy Move Forgery Detection")

menubar=Menu(root)
filemenu=Menu(menubar,tearoff=0)

filemenu.add_command(label="Open", command=OpenShowImage)
filemenu.add_command(label="DCT to Image Blocks", command=MakeDCT)
filemenu.add_command(label="Try to Detect Forgery",command=TryToDetectForgery)

filemenu.add_separator()

filemenu.add_command(label="Exit",command=root.quit)

menubar.add_cascade(label="File",menu=filemenu)

root.config(menu=menubar)

mainframe=Frame(root)
mainframe.pack(fill=BOTH)

leftframe=Frame(mainframe,width=256,height=256)
leftframe.pack(side=LEFT,padx=15,pady=25,anchor=W)

middleframe=Frame(mainframe)
middleframe.pack(side=LEFT,anchor=CENTER)

rightframe=Frame(mainframe,width=256,height=256)
rightframe.pack(side=LEFT,anchor=E,padx=15)

quantization_matrix_selection_box_label=Label(middleframe,text="Select Quantization Matrix")
quantization_matrix_selection_box_label.pack()

quantization_matrix_selection_box=ttk.Combobox(middleframe,width=15)
quantization_matrix_selection_box['values'] = ("Not Selected","QTable in Article","Q_CL","Q_90","Q_50","Q_10","Divide by 16")
quantization_matrix_selection_box.pack(anchor=CENTER,pady=3)
quantization_matrix_selection_box.current(0)

number_of_vector_to_compare_spin_label=Label(middleframe,text="Number of Vector to Compare")
number_of_vector_to_compare_spin_label.pack(pady=3)

number_of_vector_to_compare_spin = Spinbox(middleframe, from_=0, to=100,width=5,command=GetNumberOfVectorToCompare)
number_of_vector_to_compare_spin.pack(anchor=CENTER,pady=3)

maximum_Euclidean_distance_spin_label=Label(middleframe,text="Maximum Euclidean Distance")
maximum_Euclidean_distance_spin_label.pack(pady=3)

maximum_Euclidean_distance_spin = Spinbox(middleframe, from_=0, to=100,width=5,format="%.2f",increment=0.1,command=GetMaxEuclideanDistance)
maximum_Euclidean_distance_spin.pack(anchor=CENTER)

threshold_distance_for_similar_blocks_label=Label(middleframe,text="Threshold Distance for Similar Blocks")
threshold_distance_for_similar_blocks_label.pack(pady=3)

threshold_distance_for_similar_blocks_spin = Spinbox(middleframe, from_=5, to=100,width=5,command=GetThresholdDistanceForSimilarBlocks)
threshold_distance_for_similar_blocks_spin.pack(anchor=CENTER,pady=3)

min_count_for_similar_shift_vectors_label = Label(middleframe,text="Minimum Count for Similar Shift Vectors")
min_count_for_similar_shift_vectors_label.pack(pady=3)

min_count_for_similar_shift_vectors_spin = Spinbox(middleframe, from_=25, to=1000,width=5,command=GetMinCountForSimilarShiftVectors)
min_count_for_similar_shift_vectors_spin.pack(anchor=CENTER,pady=3)

accuracy_test_button=Button(middleframe,text="Accuracy Test",bg='gray' ,width=15,command=AccuracyTest)
accuracy_test_button.pack(anchor=CENTER,pady=7)

status=Label(root,text="Copy Move Forgery Detection...",bd=1,relief=SUNKEN)
status.pack(side=BOTTOM,fill=X)

root.mainloop()