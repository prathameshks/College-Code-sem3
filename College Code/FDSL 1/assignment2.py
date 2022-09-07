# Assignment 2
'''
Write a Python program to store marks scored in subject "Fundamental of Data Structure" by N students in the class. Write functions to compute following: 
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency
'''

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
	lowest = highest = present_stu_marks[0]
	
	for mark in present_stu_marks:
		pass


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
	
add_marks()

print(marks_of_stu ,present_stu_marks ,absent_stu_list ,sep='\n')

display_min_max()
"""
7
4
A
10
a
-1
9
5

"""
