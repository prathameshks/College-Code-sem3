"""
In second year computer engineering class, group A student's play cricket, group B
students play badminton and group C students play football.
Write a Python program using functions to compute following:
a) List of students who play both cricket and badminton
b) List of students who play either cricket or badminton but not both
c) Number of students who play neither cricket nor badminton
d) Number of students who play cricket and football but not badminton.
(Note- While realizing the group, duplicate entries should be avoided, Do not use SET
built-in functions)
"""


def input_list(list1: list):
    list1.clear()
    n = int(input("Enter number of students:"))
    i = 1
    while (i <= n):
        stu = int(input(f"Enter roll number of student {i}:"))
        if stu not in list1:
            list1.append(stu)
            i += 1
        else:
            print("Student already in the list")


def input_all(list1: list, list2: list, list3: list):
    print("For Cricket ", end="")
    input_list(list1)
    print("For Badminton ", end="")
    input_list(list2)
    print("For Football ", end="")
    input_list(list3)


def intersection(list1: list, list2: list):
    ans = []
    for i in list1:
        if i in list2:
            ans.append(i)
    return ans


def delta(list1: list, list2: list):
    ans = []
    for i in list1:
        if i not in list2:
            ans.append(i)
    for j in list2:
        if j not in list1:
            ans.append(j)
    return ans


def nota_notb(list1: list, list2: list, list3: list):
    count = 0
    for i in list3:
        if ((i not in list1) and (i not in list2)):
            count += 1
    return count


def a_and_b_notc(list1: list, list2: list, list3: list):
    count = 0
    a_and_b = intersection(list1, list2)
    for i in a_and_b:
        if i not in list3:
            count += 1
    return count


def main():
    group_a = [12]  # cricket
    group_b = [12]  # badminton
    group_c = [12]  # football

    input_all(group_a, group_b, group_c)

    while True:
        print("---: MENU :---")
        print("1.Reset all lists")
        print("2.List of students who play both cricket and badminton")
        print("3.List of students who play either cricket or badminton but not both")
        print("4.Number of students who play neither cricket nor badminton")
        print("5.Number of students who play cricket and football but not badminton.")
        print("6.Display all lists")
        print("7.Exit.")

        choice = input("Please enter your choice:")
        if (choice == '1'):
            input_all(group_a, group_b, group_c)
        elif (choice == '2'):
            print("List of students who play both cricket and badminton is ")
            ans = intersection(group_a, group_b)
            print(ans)
        elif (choice == '3'):
            print(
                "List of students who play either cricket or badminton but not both is ")
            ans = delta(group_a, group_b)
            print(ans)
        elif (choice == '4'):
            ans = nota_notb(group_a, group_b, group_c)
            print("Number of students who play neither cricket nor badminton is ", ans)
        elif (choice == '5'):
            ans = a_and_b_notc(group_a, group_b, group_c)
            print(
                "Number of students who play cricket and football but not badminton is ", ans)
        elif (choice == '6'):
            print("Cricket ", group_a)
            print("Badminton ", group_b)
            print("Football ", group_c)
        elif (choice == '7'):
            print("Thank you!")
            break
        else:
            print("Enter a valid choice")


main()


"""
5
1
2
6
7
8
5
1
3
10
12
8
5
1
3
6
6
12
16
"""
