"""
Write a Python program to store first year percentage of students in array. Write 
function for sorting array of floating point numbers in ascending order using quick sort 
and display top five scores.
"""


def quick_sort(arr, low, high):
    if (low < high):
        pivot = partitionate(arr, low, high)
        # recursive call for quicksort of part below and above pivot index
        quick_sort(arr, low, pivot-1)
        quick_sort(arr, pivot+1, high)


def partitionate(arr, low, high):
    pivot = arr[low]
    i = low
    j = high

    while (i < j):
        while (arr[i] <= pivot and i < len(arr)-1):
            i += 1
        while (arr[j] > pivot):
            j -= 1
        if (i < j):
            arr[i], arr[j] = arr[j], arr[i]
    arr[low], arr[j] = arr[j], arr[low]
    return j  # index of pivot in array


arr = []
n = int(input("Enter Number of Students:"))
for i in range(n):
    arr.append(float(input(f"Enter Percentage of Student{i+1}:")))

print("Array of Percentage is : ", arr)

quick_sort(arr, 0, n-1)

# top five scores using reverse indexing
print("Top five Scores are : ", arr[-1:-6:-1])


# print(arr)
"""
10
99.3
12.3
56.4
89.3
75.6
52.6
44.33
16.5
85.6
84.7

"""
