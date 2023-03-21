"""
Write a Python program to store first year percentage of students in array. Write
function for sorting array Of floating point numbers in ascending order using quick sort
and display top five scores.
"""


def input_arr():
    arr = []
    n = int(input("Enter number of students:"))
    for i in range(n):
        elmt = float(input("Enter roll number:"))
        arr.append(elmt)
    return arr


def dispaly_arr(arr):
    print("Array is :")
    for i in arr:
        print(i, end=" ")
    print()


def partitionate(arr, start, end):
    pivot = start
    i = start
    j = end
    while (i < j):
        while (arr[i] <= arr[pivot] and i<end):
            i += 1
        while (arr[j] > arr[pivot]):
            j -= 1
        if (i < j):
            arr[i], arr[j] = arr[j], arr[i]
    arr[pivot], arr[j] = arr[j], arr[pivot]
    return j


def quicksort(arr, start, end):
    if (start < end):
        pivot = partitionate(arr, start, end)
        quicksort(arr, start, pivot-1)
        quicksort(arr, pivot+1, end)


def main():
    # arr = [12.3, 15.3, 96.3, 45.2, 65.3, 88.0, 11.0, 55.0, 63.1, 78.6]
    arr = input_arr()
    print("Array before sort is ", arr)
    quicksort(arr, 0, len(arr)-1)
    print("Array after sort is ", arr)


main()

"""
10
12.3
15.3
96.3
45.2
65.3
88
11
55
63.1
78.6

"""