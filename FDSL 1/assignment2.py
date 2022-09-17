# Assignment 2
'''
Write a Python program to store marks scored in subject "Fundamental of Data Structure" by N students in the class. Write functions to compute following: 
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency
'''

# global lists for present absent total students
marks_of_stu = []
present_stu_marks = []
absent_stu_list = []

def add_marks():
	# addign marks to list
	n = int(input("Enter total number of students :"))
	print("Enter A/a/-1 for Absent student")
	for i in range(n):
		mark = input(f"Enter marks of student with roll number {i+1} :")
		marks_of_stu.append(mark)
	# separating absent and present sudents
	for mark in marks_of_stu:
		if mark in ('a','A','-1'):
			absent_stu_list.append(mark)
		else:
			present_stu_marks.append(int(mark))

def find_average():
	sum = 0
	n = 0
	for mark in present_stu_marks:
		sum += mark
		n+=1
	
	print("Average of the class is %.2f"%(sum/n))

def display_min_max():
	# initialize lowest and highest marks to index 0
	lowest = highest = present_stu_marks[0]
	for mark in present_stu_marks:
		if mark<lowest:
			lowest = mark
		if mark>highest:
			highest=mark
	
	print("Highest score of the class is", highest)
	print("Lowest score of the class is", lowest)


def find_max_frequency():
	marks = []
	freq = []
	for i in present_stu_marks:
		if i not in marks:
			marks.append(i)
			freq.append(1)
		else:
			index = marks.index(i)
			freq[index] += 1
	max_mark = []
	max = freq[0]
	for i in range(len(freq)):
		if freq[i]>max:
			max = freq[i]
	
	for i in range(len(freq)):
		if freq[i] == max:
			max_mark.append(marks[i])
	if len(max_mark) == 1:
		print("The marks with highest frequency is", max_mark[0])
	else:
		print("The marks with highest frequency are", max_mark)

add_marks()

while True:
	print("--MENU--")
	print("1. The Average score ")
	print("2. Highest and Lowest score")
	print("3. Count of students who were absent for the test")
	print("4. Display mark with highest frequency")
	print("5. Re Enter the marks")
	print("6. Exit the code")
	choice = input("Enter your choice :")

	if choice == '1':
		find_average()
	elif choice == '2':
		display_min_max()
	elif choice == '3':
		print("The number of students absent for the test are", len(absent_stu_list))
	elif choice == '4':
		find_max_frequency()
	elif choice == '5':
			# global lists for present absent total students
		marks_of_stu = []
		present_stu_marks = []
		absent_stu_list = []
		add_marks()
	elif choice == '6':
		break
	else:
		print("Please Enter a valid choice.")
	print("-"*50)
print("Successfully Exited")
input()
"""
10
4
A
10
a
-1
9
5
4
5
4

"""
