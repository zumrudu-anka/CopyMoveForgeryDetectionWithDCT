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

def GetMinDistValue(value):
	if(value<0):
		a=int(value)
		if(abs(value-a)<abs(value-(a-1))):
			return a
		else:
			return a-1
	else:
		a=int(value)
		if(abs(value-a)<abs(value-(a+1))):
			return a
		else:
			return a+1