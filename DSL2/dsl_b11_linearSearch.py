"""
Write a Python program to store roll numbers of student in array who attended training program in random order. Write function for searching whether particular student attended training program or not, using Linear search and Sentinel search.
"""

def linersearch(lst,elmt,n):
	for i in range(n):
		if lst[i]==elmt:
			return i
	return -1

# C / C++ Style code ie can not append in list
def sentinelsearch(lst,elmt,n):
	last = lst[n-1]
	lst[n-1] = elmt
	i=0
	while (lst[i] != elmt):
		i+=1
		
	if i < n-1 or elmt == last:
		return i
	else:
		return -1

# python code ie can append in list
def sentinelsearch2(lst,elmt,n):
	lst.append(elmt)
	i=0
	while (lst[i] != elmt):
		i+=1
		
	if i < n:
		return i
	else:
		return -1


a=[]
n=int(input("Enter number of students:"))

for i in range(n):
	a.append(int(input("Enter roll number:")))
	
print("List is ",a)

while True:
	print("-"*30)
	print("MENU".center(30))
	print("1. Use liner Search\n2. Use Sentinal Search\n3. Exit")
	choice = int(input("Enter your choice:"))
	if choice==1:
		elmt = int(input("Enter roll number to search:"))
		res = linersearch(a,elmt,n)
		if res == -1:
			print("Student has not attended training.")
		else:
			print("Student has attended training, Found at index",res)
			
	elif choice==2:
		elmt = int(input("Enter roll number to search:"))
		res = sentinelsearch2(a,elmt,n)
		if res == -1:
			print("Student has not attended training.")
		else:
			print("Student has attended training, Found at index",res)
			
	elif choice==3:
		break
	else:
		print("Enter a valid choice")
		
"""
10
1
4
6
9
7
5
12
63
6
3

"""
	
