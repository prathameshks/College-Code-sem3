def binary_search(arr,start,end,key):
    if end>=start:
        mid = (start+end)//2
        if (arr[mid]==key):
            return mid
        elif(arr[mid]>key):
            return binary_search(arr,start,mid-1,key)
        else:
            return binary_search(arr,mid+1,end,key)
    else:
        return -1

def fibo_search(arr,key):
    n=len(arr)
    fibo = [0,1]
    while(fibo[-1]<n):
        fibo.append(fibo[-2]+fibo[-1])
    offset = -1
    m = len(fibo)-1
    while(fibo[m]>0):
        i = min(offset+fibo[m-2],n-1)
        if arr[i]<key:
            m-=1
            offset = i
        elif arr[i]>key:
            m-=2
        else:
            return i
    return -1

def enter_array():
    arr=[]
    n=int(input("Enter number of students:"))
    # input array in random order
    for _ in range(n):
        arr.append(int(input("Enter roll number:")))
    # sorting array using selection sort
    for i in range(n):
        min_ind = i
        for j in range(i + 1, n):
            if (arr[j] < arr[min_ind]):
                min_ind = j
        if(min_ind != i):
            arr[i], arr[min_ind]= arr[min_ind],arr[i];
    return arr

arr = enter_array()
while True:
    print("-"*30)
    print("MENU".center(30))
    print("1. Enter array\n2. Display Array\n3. Use Binary Search\n4. Use Fibonacci Search\n5. Exit")
    choice = int(input("Enter your choice:"))
    if choice==1:
        arr = enter_array()
        print("Array Created Sucessfully")
        
    elif choice==2:
        print("Array is ",arr)
        
    elif choice==3:
        elmt = int(input("Enter roll number to search:"))
        res = binary_search(arr,0,len(arr)-1,elmt)
        if res == -1:
            print("Student has not attended training.")
        else:
            print("Student has attended training, Found at index",res)
    
    elif choice==4:
        elmt = int(input("Enter roll number to search:"))
        res = fibo_search(arr,elmt)
        if res == -1:
            print("Student has not attended training.")
        else:
            print("Student has attended training, Found at index",res)

    elif choice==5:
        print("Thank You.")
        break
    else:
        print("Enter a valid choice")
        
t=input("")

""" 
10
1
4
6
9
7
5
2
10
8
3
4

"""
"""
Write a Python program to store roll numbers of student array who attended training
program in sorted order. Write function for searching whether particular student
attended training program or not, using Binary search and Fibonacci search
"""
