"""
Write a Python program to store first year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.
"""


def input_arr():
    arr = []
    n = int(input("Enter number of students:"))
    for i in range(n):
        elmt = int(input("Enter roll number:"))
        arr.append(elmt)
    return arr


def dispaly_arr(arr):
    print("Array is :")
    for i in arr:
        print(i, end=" ")
    print()


def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1, 0, -1):
        for j in range(i):
            if (arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1], arr[j]


def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        m = i
        for j in range(i, n):
            if (arr[j] < arr[m]):
                m = j
        if (m != i):
            arr[i], arr[m] = arr[m], arr[i]


def main():

    while True:
        print("---: MENU :---")
        print("1.Bubble Sort ")
        print("2.Selection sort")
        print("3.Exit.")

        choice = input("Please enter your choice:")
        if (choice == '1'):
            arr = input_arr()
            print("Array before sort :", arr)
            bubble_sort(arr)
            print("Array After sort :", arr)
            print("Top 5 Scores are :", arr[-1:-6:-1])

        elif (choice == '2'):
            arr = input_arr()
            print("Array before sort :", arr)
            selection_sort(arr)
            print("Array After sort :", arr)
            print("Top 5 Scores are :", arr[-1:-6:-1])

        elif (choice == '3'):
            print("Thank you!")
            break
        else:
            print("Enter a valid choice")


if __name__ == "__main__":
    main()
