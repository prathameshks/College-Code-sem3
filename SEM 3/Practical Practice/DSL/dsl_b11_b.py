"""
b) Write a Python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search
"""


def input_arr():
    arr = []
    n = int(input("Enter number of students:"))
    for i in range(n):
        elmt = int(input("Enter roll number:"))
        j = 0
        while (j != i and arr[j] < elmt):
            j += 1
        arr.insert(j, elmt)
    return arr


def dispaly_arr(arr):
    print("Array is :")
    for i in arr:
        print(i, end=" ")
    print()


def binary_search(arr, key):
    start = 0
    end = len(arr)-1
    while (start <= end):
        mid = start + (end-start)//2
        if (arr[mid] == key):
            return mid
        elif (arr[mid] < key):
            start = mid+1
        else:
            end = mid - 1
    return -1


def fibonacci_search_witharray(arr, key):
    n = len(arr)
    offset = -1
    fibo = [0, 1]
    m = 1
    while (fibo[m] < n):
        fibo.append(fibo[m]+fibo[m-1])
        m += 1

    while (fibo[m-2] >= 0):
        i = min(offset+fibo[m-2], n-1)

        if (arr[i] < key):
            offset = i
            m -= 2
        elif (arr[i] > key):
            m -= 1
        else:
            return i

    return -1


def fibonacci_search(arr, key):
    n = len(arr)
    start = -1
    fibom2 = 0
    fibom1 = 1
    fibom = 1
    while (fibom < n):
        fibom += fibom1
        fibom2 = fibom1
        fibom1 = fibom - fibom1

    while (fibom > 0):
        i = min(start+fibom2, n-1)

        if (arr[i] < key):
            start = i
            fibom = fibom2
            fibom1 -= fibom2
            fibom2 = fibom - fibom1
        elif (arr[i] > key):
            fibom2 = fibom1 - fibom2
            fibom1 = fibom - fibom1
            fibom = fibom1 + fibom2
        else:
            return i
    return -1


def main():
    arr = input_arr()
    while True:
        print("---: MENU :---")
        print("1.Enter Array ")
        print("2.Display Array")
        print("3.Use Binary Search")
        print("4.Use Fibonacci Search")
        print("5.Exit.")

        choice = input("Please enter your choice:")
        if (choice == '1'):
            arr = input_arr()

        if (choice == '2'):
            dispaly_arr(arr)

        elif (choice == '3'):
            key = int(input("Enter element to search:"))
            index = binary_search(arr, key)
            if (index == -1):
                print("Student not attended Section")
            else:
                print("Student present at index ", index)

        elif (choice == '4'):
            key = int(input("Enter element to search:"))
            index = fibonacci_search(arr, key)
            if (index == -1):
                print("Student not attended Section")
            else:
                print("Student present at index ", index)

        elif (choice == '5'):
            print("Thank you!")
            break
        else:
            print("Enter a valid choice")


main()
# a=[1,2,3,4,5,6,7,8,9,10]
# for i in a:
#     print(fibonacci_search_witharray(a,i))
