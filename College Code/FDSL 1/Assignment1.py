
# for getting roll number in a list
def get_student_list(game):
    lst = []
    n = int(input(f"Enter Number of Students Playing {game} :"))
    for i in range(n):
        roll_no = int(input(f"Enter roll no.({i+1}):"))
        lst.append(roll_no)
    print(f"{game} players are : ", lst)
    return lst


# function for union of two lists
def union(x, y):
    unionist = x + y
    for i in x:
        if i in y:
            unionist.remove(i)
    return unionist


# function for intersection of two lists
def intersection(x, y):
    inter_list = []
    for i in x:
        if i in y:
            inter_list.append(i)
    return inter_list


# function for list a - list b
def list_difference(list_a, list_b):
    result = []
    for i in list_a:
        if i not in list_b:
            result.append(i)
    return result


# display lists of all players
def display_lists():
    print("Cricket :", group_a)
    print("Badminton :", group_b)
    print("Football :", group_c)


# Declaration variables and lists 
total_students = int(input("Enter Total Number of Students :"))
group_a = get_student_list("Cricket")
group_b = get_student_list("Badminton")
group_c = get_student_list("Football")
exit_choice = True

# while loop for user menu
while True:
    print("--MENU--")
    print("1.Display Players lists")
    print("2.List of Student playing both cricket and badminton")
    print("3.List of Student playing both either cricket or badminton but not both")
    print("4.Number of students who play neither cricket nor badminton")
    print("5.Number of students who play cricket and football but not badminton")
    choice = input("Enter your choice :")

    if choice == '1':
        display_lists()

    elif choice == '2':
        both_a_and_b = intersection(group_a, group_b)
        print("List of Student playing both cricket and badminton is ", both_a_and_b)

    elif choice == '3':
        a_and_b_not_both = list_difference(
            union(group_a, group_b), intersection(group_a, group_b))
        print("List of Student playing both either cricket or badminton but not both", a_and_b_not_both)

    elif choice == '4':
        no_not_a_or_b = total_students - len(union(group_a, group_b))
        print(
            "Number of students who play neither cricket nor badminton is ", no_not_a_or_b)

    elif choice == '5':
        no_a_c_not_b = list_difference(union(group_a, group_c), group_b)
        print("Number of students who play cricket and football but not badminton is ", len(
            no_a_c_not_b))

    else:
        print("Please Enter a valid choice.(•_•)")
        exit_choice = False  # if choice is invalid no need to ask for exit

    if exit_choice:
        want_continue = input("Do you want to Exit:")
        if want_continue == 'y' or want_continue == 'Y':
            break
    exit_choice = True

print("Successfully Exited... (^_^)")

a=input()
'''
10
6
1
3
4
6
7
9
6
2
4
5
6
7
9
5
1
4
6
7
8

'''
