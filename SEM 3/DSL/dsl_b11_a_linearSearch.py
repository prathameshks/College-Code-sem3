def linearsearch(lst, elmt, n):
    for i in range(n):
        if lst[i] == elmt:
            return i
    return -1


def sentinelsearch(lst, elmt, n):
    last = lst[n-1]
    lst[n-1] = elmt
    i = 0
    while (lst[i] != elmt):
        i += 1

    if i < n-1 or elmt == last:
        return i
    else:
        return -1


a = []
n = int(input("Enter number of students:"))

for i in range(n):
    a.append(int(input("Enter roll number:")))
print("List is ", a)

while True:
    print("-"*30)
    print("MENU".center(30))
    print("1. Use linear Search\n2. Use Sentinel Search\n3. Exit")
    choice = int(input("Enter your choice:"))
    if choice == 1:
        elmt = int(input("Enter roll number to search:"))
        res = linearsearch(a, elmt, n)
        if res == -1:
            print("Student has not attended training.")
        else:
            print("Student has attended training, Found at index", res)

    elif choice == 2:
        elmt = int(input("Enter roll number to search:"))
        res = sentinelsearch(a, elmt, n)
        if res == -1:
            print("Student has not attended training.")
        else:
            print("Student has attended training, Found at index", res)

    elif choice==3:
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
8
2
10
3



# C / C++ Style code ie can not append in list
def sentinelsearch1(lst,elmt,n):
    last = lst[n-1]
    lst[n-1] = elmt
    i=0
    while (lst[i] != elmt):
        i+=1
        
    if i < n-1 or elmt == last:
        return i
    else:
        return -1

# python code ie can append in list
def sentinelsearch2(lst,elmt,n):
    lst.append(elmt)
    i=0
    while (lst[i] != elmt):
        i+=1
        
    if i < n:
        return i
    else:
        return -1

"""
    
"""
Write a Python program to store roll numbers of student in array who attended training program in random order. Write function for searching whether particular student attended training program or not, using Linear search and Sentinel search.
"""
