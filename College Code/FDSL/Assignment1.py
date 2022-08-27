print("Hello World")
def enter_students(n, lst):
        for i in range(n):
                rollno = int(input("Enter roll no.:"))
                        lst.append(rollno)


                        def union(x, y):
                            unilst = x + y
                                for i in x:
                                        if i in y:
                                                    unilst.remove(i)
                                                        return unilst


                                                        def intersetion(x, y):
                                                            interlst = []
                                                                for i in x:
                                                                        if i in y:
                                                                                    interlst.append(i)
                                                                                        return interlst


                                                                                        def either_sport(x, y):
                                                                                            eitherlst = x + y
                                                                                                for i in x:
                                                                                                        if i in y:
                                                                                                                    eitherlst.remove(i)
                                                                                                                                eitherlst.remove(i)
                                                                                                                                    return eitherlst


                                                                                                                                    def count_neither(x, y):
                                                                                                                                        uni = union(x, y)
                                                                                                                                            return len(studentlst) - len(uni)


                                                                                                                                            def count_play2_but_not1(x, y, z):
                                                                                                                                                uni = union(x, y)
                                                                                                                                                    count = len(uni) - len(intersetion(uni, z))
                                                                                                                                                        return count


                                                                                                                                                        def show_play2_but_not1(x, y, z):
                                                                                                                                                            uni = union(x, y)
                                                                                                                                                                inter = (intersetion(uni, z))
                                                                                                                                                                    for i in inter:
                                                                                                                                                                            if i in uni:
                                                                                                                                                                                        uni.remove(i)
                                                                                                                                                                                            return uni


                                                                                                                                                                                            studentlst = [int(x) for x in range(1, int(input("Enter total number of students:")))]

                                                                                                                                                                                            cricket = []
                                                                                                                                                                                            badminton = []
                                                                                                                                                                                            football = []
                                                                                                                                                                                            no_c = int(input("Enter number of students in Cricket:"))
                                                                                                                                                                                            enter_students(no_c, cricket)
                                                                                                                                                                                            no_b = int(input("Enter number of students in Badminton:"))
                                                                                                                                                                                            enter_students(no_b, badminton)
                                                                                                                                                                                            no_f = int(input("Enter number of students in Football:"))
                                                                                                                                                                                            enter_students(no_f, football)

                                                                                                                                                                                            print(cricket)
                                                                                                                                                                                            print(badminton)
                                                                                                                                                                                            print(football)

                                                                                                                                                                                            print("Student who play both cricket and badminton:", union(cricket, badminton))
                                                                                                                                                                                            print("student who play either cricket or badminton but not both:", either_sport(cricket, badminton))
                                                                                                                                                                                            print("No. of students who play neither cricket nor badminton:", count_neither(cricket, badminton))
                                                                                                                                                                                            print("No. of students who play cricket and football but not badminton:",
                                                                                                                                                                                                  count_play2_but_not1(cricket, football, badminton))