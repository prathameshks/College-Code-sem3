"""
Write a Python program to store first year percentage of students in array. Write 
function for sorting array of floating point numbers in ascending order using 
a) Selection Sort 
b) Bubble sort and display top five scores.
"""


def bubble_sort(arr):
    n = len(arr)  # size of array
    for i in range(n):  # for each index
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]


arr = []
n = int(input("Enter Number of Students:"))
for i in range(n):
    arr.append(float(input(f"Enter Percentage of Student{i+1}:")))

print("Array of Percentage is : ", arr)

bubble_sort(arr)

# top five scores using reverse indexing
print("Top five Scores are : ", arr[-1:-6:-1])

void merge(int *arr, int left, int right, int mid)
{
    int i, j, k, ans[50];
    i = left;
    k = left;
    j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            ans[k] = arr[i];
            k++;
            i++;
        }
        else  {
            ans[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        ans[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right) {
        ans[k] = arr[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)  {
        arr[i] = ans[i];
    }
}