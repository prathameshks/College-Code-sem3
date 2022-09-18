'''
Write a Python program to compute following computation on matrix:
a) Addition of two matrices 
b) Subtraction of two matrices
c) Multiplication of two matrices 
d) Transpose of a matrix
'''

def display(matrix):
	for row in matrix:
		for element in row:
			print(element,end = " ")
		print()

def read(row,col):
	matrix = []
	for i in range(row):
		matrix.append([])
		for j in range(col):
			elmt = int(input(f"Enter element in row {i+1} and column {j+1}:"))
			matrix[i].append(elmt)
	return matrix

def addition(mat1,mat2):
	r1,r2 = len(mat1),len(mat2)
	c1,c2 = len(mat1[0]),len(mat2[0])
	add = []
	if ((r1!=r2) or (c1!=c2)):
		return 0
	else:
		for i in range(r1):
			add.append([])
			for j in range(c1):
				add[i].append(mat1[i][j]+mat2[i][j])
		return add
		
def subtraction(mat1,mat2):
	r1,r2 = len(mat1),len(mat2)
	c1,c2 = len(mat1[0]),len(mat2[0])
	sub = []
	if ((r1!=r2) or (c1!=c2)):
		return 0
	else:
		for i in range(r1):
			sub.append([])
			for j in range(c1):
				sub[i].append(mat1[i][j]-mat2[i][j])
		return sub

def multiplication(mat1,mat2):
	r1,r2 = len(mat1),len(mat2)
	c1,c2 = len(mat1[0]),len(mat2[0])
	multi = []
	if (c1!=r2):
		return 0
	else:
		for i in range(r1):
			multi.append([])
			for j in range(c2):
				sum = 0
				for k in range(c1):
					sum += mat1[i][k]*mat2[k][j]
				multi[i].append(sum)
		return multi

def transpose(matrix):
	trans = []
	row = len(matrix)
	col = len(matrix[0])
	for i in range(col):
		trans.append([])
		for j in range(row):
			elmt = matrix[j][i]
			trans[i].append(elmt)
	return trans

def main():
	while True:
		print("MENU".center(50,'-'))
		print("1. Addition of two matrices ")
		print("2. Subtraction of two matrices")
		print("3. Multiplication of two matrices ")
		print("4. Transpose of a matrix")
		ch = input("Enter your choice :")
		if ch == '1':
			can_add = False
			while not can_add:
				r1 = int(input("Enter number of rows in matrix 1:"))
				c1 = int(input("Enter number of columns in matrix 1:"))
				
				r2 = int(input("Enter number of rows in matrix 2:"))
				c2 = int(input("Enter number of columns in matrix 2:"))

				if ((r1!=r2) or (c1!=c2)):
					print("Order of both Matrix should be Same to Perform Addition.")
				else:
					can_add = True
			print("*Enter Matrix 1")
			mat1 = read(r1,c1)
			print("*Enter Matrix 2")
			mat2 = read(r2,c2)
			


			
def main1():
	print("MENU".center(50,'-'))
	m = read(4,3)
	# n = read(3,3)
	print('matrix 1')
	display(m)
	# print('matrix 2')
	# display(n)
	ans = transpose(m)
	if ans:
		print('Ans is')
		display(ans)
	else:
		#print("Order of both Matrix should be Same to Perform Subtraction.")
		# print("Number of columns of Matrix 1 should be equal to Number of rows of Matrix 2 for Performing Multiplication.")
		print("trans error")

main()

"""
1
2
3
6
9
5
8
4

""",
