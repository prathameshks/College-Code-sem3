"""
Write a Python program to store marks scored in subject "Fundamental of Data
Structure" by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency
"""


def input_marks(list1: list):
    list1.clear()
    n = int(input("Enter number of students:"))
    i = 1
    print("Enter -1 for absent student marks")
    while (i <= n):
        stu = int(input(f"Enter Marks of student {i}:"))
        list1.append(stu)
        i += 1


def average(list1: list):
    total = 0
    present_count = 0
    for i in list1:
        if (i >= 0):
            total += i
            present_count += 1
    avg = total/present_count
    return avg


def min_max(list1: list):
    min_marks = list1[0]
    max_marks = list1[0]

    for i in list1:
        if (i >= 0):
            if (i > max_marks):
                max_marks = i
            if (i < min_marks):
                min_marks = i

    return min_marks, max_marks


def absent_count(list1: list):
    absent_cnt = 0

    for i in list1:
        if (i < 0):
            absent_cnt += 1

    return absent_cnt


def max_freq(list1: list):
    freq = dict()

    for i in list1:
        if (i >= 0):
            if i not in freq.keys():
                freq[i] = 1
            else:
                freq[i] += 1

    max_times = list1[0]

    for j in freq.keys():
        if freq[j] > freq[max_times]:
            max_times = j

    return max_times,freq[max_times]


def main():
    fds_marks = []
    input_marks(fds_marks)

    while True:
        print("---: MENU :---")
        print("1.Reset marks list")
        print("2.Display all marks")
        print("3.The average score of class")
        print("4.Highest score and lowest score of class")
        print("5.Count of students who were absent for the test")
        print("6.Display mark with highest frequency")
        print("7.Exit.")

        choice = input("Please enter your choice:")
        if (choice == '1'):
            input_marks(fds_marks)

        elif (choice == '2'):
            print("Marks of students are ")
            print(fds_marks)

        elif (choice == '3'):
            ans = average(fds_marks)
            print("Average of the class is ",ans)

        elif (choice == '4'):
            ansmin,ansmax = min_max(fds_marks)
            print("Highest score of the class is ",ansmax)
            print("Lowest score of the class is ",ansmin)

        elif (choice == '5'):
            ans = absent_count(fds_marks)
            print("Count of absent students in the class is ",ans)
        
        elif (choice == '6'):
            marks,freq = max_freq(fds_marks)
            print("Maximun frequency marks of the class is ",marks," with freq of ",freq)

        elif (choice == '7'):
            print("Thank you!")
            break
        else:
            print("Enter a valid choice")


main()


"""
20
5
1
2
6
-7
8
0
1
3
10
12
8
5
1
0
6
6
12
-1
3
"""
