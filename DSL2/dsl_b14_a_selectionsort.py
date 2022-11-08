"""
Write a Python program to store first year percentage of students in array. Write 
function for sorting array of floating point numbers in ascending order using 
a) Selection Sort 
b) Bubble sort and display top five scores.
"""


def selection_sort(arr):
    n = len(arr)  # size of array
    for i in range(n):  # for each index
        min = i  # default minimun to i th index
        for j in range(i+1, n):
            if arr[j] < arr[min]:
                min = j
        if min != i:  # swap min with i
            arr[i], arr[min] = arr[min], arr[i]


arr = []
n = int(input("Enter Number of Students:"))
for i in range(n):
    arr.append(float(input(f"Enter Percentage of Student{i+1}:")))

print("Array of Percentage is : ", arr)

selection_sort(arr)

# top five scores using reverse indexing
print("Top five Scores are : ", arr[-1:-6:-1])
