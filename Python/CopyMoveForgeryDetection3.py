import cv2
import numpy as np
import scipy.ndimage
from operator import itemgetter
import math

img=cv2.imread('Kucukler/forged1.png',0)

cv2.namedWindow('image',cv2.WINDOW_NORMAL)
cv2.imshow('image',img)
cv2.waitKey(0)
cv2.destroyAllWindows()
height, width = img.shape

vis0=np.zeros((height,width),np.float32)

vis0[:height,:width]=img

def getdiagonalarray(matrix,rows,columns):
	solution=[[] for i in range(rows+columns-1)]
	for i in range(rows):
		for j in range(columns):
			sum=i+j
			if(sum%2==0):
				solution[sum].insert(0,matrix[i][j])
			else:
				solution[sum].append(matrix[i][j])
	result=[]
	count=0
	row=0
	for k in range(rows+columns-1):
		for t in solution[k]:
			count+=1
			result.append(t)
			if(count==15):
				return result

def GetQuantizationMatrix(size,mainsize):
	for i in range (0,size):
		for j in range(0,size):
			quantization_matrix[i][j]=(pow(2,size-2))
	if (size != 2):
		GetQuantizationMatrix(size-1,mainsize)


quantization_matrix=[[] for i in range(0,8)]

for i in quantization_matrix:
	for j in range(0,8):
		i.append(0)

GetQuantizationMatrix(8,8)

diagonaled_array=[[] for i in range((height-7)*(width-7))]
count=0

quantization_mtrx=GetQuantizationMatrix(8,8)


for i in range (0,height-7):
	for j in range(0,width-7):

		####	Make Quantization With Quantization Matrix    ####

		vis1 = cv2.dct(vis0[i:i+8,j:j+8])
		for k in range(0,8):
			for t in range(0,8):
				vis1[k][t]=vis1[k][t]/quantization_matrix[k][t]
		vis1=getdiagonalarray(vis1,8,8)

		##############    Not Make Quantization 	##############

		
		#vis1 = getdiagonalarray(cv2.dct(vis0[i:i+8,j:j+8]), 8, 8)

		########    Make Quantization With Division 16    ########

		#vis1 = [x / 16 for x in vis1]

		diagonaled_array[count].append(vis1)
		diagonaled_array[count].append([i,j])
		count+=1
		

dmax = math.sqrt(pow((height-7),2)+pow((width-7),2))

hough_space=[]


diagonaled_array.sort(key=itemgetter(0))

for i in range(0,len(diagonaled_array)-9):
	toplam = 0.0
	for j in range(i+1,i+10):
		for k in range(0,15):
			toplam += pow(( diagonaled_array[i][0][k] - diagonaled_array[j][0][k]), 2)
		if(math.sqrt(toplam) < 2.5):
			hough_space.append(diagonaled_array[i][1][0])
			hough_space.append(diagonaled_array[i][1][1])
			hough_space.append(diagonaled_array[j][1][0])
			hough_space.append(diagonaled_array[j][1][1])
			hough_space.append([abs(diagonaled_array[i][1][0]-diagonaled_array[j][1][0]),abs(diagonaled_array[i][1][1]-diagonaled_array[j][1][1])])


img2 = np.zeros((height,width,1),np.uint8)


for i in range(4,len(hough_space),5):
	if(hough_space.count(hough_space[i]) > 100):
		img2[hough_space[i-4],hough_space[i-3],0]=255
		img2[hough_space[i-2],hough_space[i-1],0]=255

cv2.imshow('image',img2)
cv2.waitKey(0)
cv2.destroyAllWindows()