import cv2
import numpy as np
import scipy.ndimage
from operator import itemgetter
import math
from tkinter import *
from tkinter import messagebox
from MyFunctions import *

def OpenShowImage():
	global img,firstimage,first_image_label
	firstimage=PhotoImage(file='Forged Images/forged1.png')
	first_image_label=Label(leftframe,image=firstimage)
	first_image_label.pack()
	img=cv2.imread('Forged Images/forged1.png',0)

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

			####	Make Quantization With Quantization Matrix    ####

			vis1 = cv2.dct(vis0[i:i+8,j:j+8])
			for k in range(0,8):
				for t in range(0,8):
					vis1[k][t] = GetMinDistValue(vis1[k][t] / quantization_matrix[k][t])
			vis1 = getdiagonalarray(vis1,8,8)

			##############    Not Make Quantization 	##############

			
			#vis1 = getdiagonalarray(cv2.dct(vis0[i:i+8,j:j+8]), 8, 8)

			########    Make Quantization With Division 16    ########

			#vis1 = [x / 16 for x in vis1]

			diagonaled_array[count].append(vis1)
			diagonaled_array[count].append([i,j])
			count+=1
	messagebox.showinfo("Success","DCT Dönüşüm Tamamlandı")

number_of_vector_to_compare=10
max_euclidean_distance=1.0
threshold_distance_for_similar_blocks=5
min_count_for_similar_shift_vectors=10

def TryToDetectForgery():
	global hough_space,result_image,result_image_label
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
			img2[hough_space[i-4],hough_space[i-3],0]=255
			img2[hough_space[i-2],hough_space[i-1],0]=255

	cv2.imwrite('resultimage.png',img2)
	result_image=PhotoImage(file='resultimage.png')
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
root.geometry("800x300")

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

number_of_vector_to_compare_spin_label=Label(middleframe,text="Number of Vector to Compare")
number_of_vector_to_compare_spin_label.pack()

number_of_vector_to_compare_spin = Spinbox(middleframe, from_=0, to=100,width=5,command=GetNumberOfVectorToCompare)
number_of_vector_to_compare_spin.pack(anchor=CENTER)

maximum_Euclidean_distance_spin_label=Label(middleframe,text="Maximum Euclidean Distance")
maximum_Euclidean_distance_spin_label.pack()

maximum_Euclidean_distance_spin = Spinbox(middleframe, from_=0, to=100,width=5,format="%.2f",increment=0.1,command=GetMaxEuclideanDistance)
maximum_Euclidean_distance_spin.pack(anchor=CENTER)

threshold_distance_for_similar_blocks_label=Label(middleframe,text="Threshold Distance for Similar Blocks")
threshold_distance_for_similar_blocks_label.pack()

threshold_distance_for_similar_blocks_spin = Spinbox(middleframe, from_=5, to=100,width=5,command=GetThresholdDistanceForSimilarBlocks)
threshold_distance_for_similar_blocks_spin.pack(anchor=CENTER)

min_count_for_similar_shift_vectors_label = Label(middleframe,text="Minimum Count for Similar Shift Vectors")
min_count_for_similar_shift_vectors_label.pack()

min_count_for_similar_shift_vectors_spin = Spinbox(middleframe, from_=10, to=100,width=5,command=GetMinCountForSimilarShiftVectors)
min_count_for_similar_shift_vectors_spin.pack(anchor=CENTER)


status=Label(root,text="Copy Move Forgery Detection...",bd=1,relief=SUNKEN)
status.pack(side=BOTTOM,fill=X)

root.mainloop()

