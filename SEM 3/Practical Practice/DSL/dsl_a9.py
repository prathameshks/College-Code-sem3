"""
Write a Python program to compute following computation on matrix:
a) Addition Of two matrices 
B) Subtraction Of two matrices
c) Multiplication of two matrices 
d) Transpose of a matrix
"""


def input_matrix(n, m):
    mat = []
    for i in range(n):
        mat.append([])
        for j in range(m):
            elmt = int(input(f"Enter Element at position ({i+1},{j+1}):"))
            mat[i].append(elmt)
    return mat


def display_matrix(mat: list[list]):
    n = len(mat)
    m = len(mat[0])
    for i in range(n):
        for j in range(m):
            print(mat[i][j], end=" ")
        print()


def addition(mat1: list[list], mat2: list[list]):
    n = len(mat1)
    m = len(mat1[0])
    ans = []
    for i in range(n):
        ans.append([])
        for j in range(m):
            calc = mat1[i][j] + mat2[i][j]
            ans[i].append(calc)
    return ans


def substraction(mat1: list[list], mat2: list[list]):
    n = len(mat1)
    m = len(mat1[0])
    ans = []
    for i in range(n):
        ans.append([])
        for j in range(m):
            calc = mat1[i][j] - mat2[i][j]
            ans[i].append(calc)
    return ans


def multiplication(mat1: list[list], mat2: list[list]):
    r1 = len(mat1)
    c1 = len(mat1[0])
    c2 = len(mat2[0])

    ans = []
    for i in range(r1):
        ans.append([])
        for j in range(c2):
            sum_row = 0
            for k in range(c1):
                sum_row += (mat1[i][k] * mat2[k][j])
            ans[i].append(sum_row)
    return ans


def transpose(mat1: list[list]):
    n = len(mat1)
    m = len(mat1[0])
    ans = []
    for i in range(m):
        ans.append([])
        for j in range(n):
            ans[i].append(mat1[j][i])
    return ans


def main():
    while True:
        print("---: MENU :---")
        print("1.Addition Of two matrices ")
        print("2.Subtraction Of two matrices")
        print("3.Multiplication of two matrices ")
        print("4.Transpose of a matrix")
        print("5.Exit.")

        choice = input("Please enter your choice:")
        if (choice == '1'):
            n = int(input("Enter number of rows in matrix:"))
            m = int(input("Enter number of columns in matrix:"))
            print("For matrix 1")
            mat1 = input_matrix(n, m)
            print("For matrix 2")
            mat2 = input_matrix(n, m)
            ans = addition(mat1, mat2)
            print("Addition is ")
            display_matrix(ans)

        elif (choice == '2'):
            n = int(input("Enter number of rows in matrix:"))
            m = int(input("Enter number of columns in matrix:"))
            print("For matrix 1")
            mat1 = input_matrix(n, m)
            print("For matrix 2")
            mat2 = input_matrix(n, m)
            ans = substraction(mat1, mat2)
            print("Substraction is ")
            display_matrix(ans)

        elif (choice == '3'):
            n = int(input("Enter number of rows in matrix 1:"))
            m = int(input("Enter number of columns in matrix 1 & rows in matrix 2:"))
            p = int(input("Enter number of columns in matrix 2:"))
            print("For matrix 1")
            mat1 = input_matrix(n, m)
            print("For matrix 2")
            mat2 = input_matrix(m, p)
            ans = multiplication(mat1, mat2)
            print("Multiplication is ")
            display_matrix(ans)

        elif (choice == '4'):
            n = int(input("Enter number of rows in matrix:"))
            m = int(input("Enter number of columns in matrix:"))
            print("Input matrix ")
            mat1 = input_matrix(n, m)
            ans = transpose(mat1)
            print("Transpose is ")
            display_matrix(ans)

        elif (choice == '5'):
            print("Thank you!")
            break
        else:
            print("Enter a valid choice")


main()