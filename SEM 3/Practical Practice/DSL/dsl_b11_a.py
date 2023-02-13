"""
a) Write a Python program to store roll numbers of student in array who attended
training program in random order. Write function for searching whether particular
student attended training program or not, using Linear search and Sentinel search.
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
        print(i,end=" ")
    print()



def linear_search(arr, key):
    n = len(arr)
    for i in range(n):
        if arr[i] == key:
            return i
    return -1  # not present in array


def sentinal_search(arr, key):
    n = len(arr)
    last = arr[n-1]
    arr[n-1] = key
    i = 0
    while (arr[i] != key):
        i += 1

    if (i != n-1):
        return i
    if (key == last):
        return n-1
    return -1  # not present


def main():
    arr = input_arr()
    while True:
        print("---: MENU :---")
        print("1.Enter Array ")
        print("2.Display Array")
        print("3.Use Linear Search")
        print("4.Use Sentinal Search")
        print("5.Exit.")

        choice = input("Please enter your choice:")
        if (choice == '1'):
            arr = input_arr()
        
        if (choice == '2'):
            arr = dispaly_arr()

        elif (choice == '3'):
            key = int(input("Enter element to search:"))
            index = linear_search(arr, key)
            if (index == -1):
                print("Student not attended Section")
            else:
                print("Student present at index ", index)

        elif (choice == '4'):
            key = int(input("Enter element to search:"))
            index = sentinal_search(arr, key)
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
