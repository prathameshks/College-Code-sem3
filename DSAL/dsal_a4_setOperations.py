from __future__ import annotations


class sets:
    """Using Inbuild Functions"""

    def __init__(self) -> None:
        self.data = set()

    def get_data(self) -> set:
        return self.data

    def extend(self, lst: any) -> None:
        data = list(lst)
        for elmt in data:
            self.data.add(elmt)

    def add(self, elmt: any) -> None:
        self.data.add(elmt)

    def remove(self, elmt: any) -> bool:
        if (elmt in self.data):
            self.data.remove(elmt)
            return True
        else:
            return False

    def contains(self, elmt: any) -> bool:
        return (elmt in self.data)

    def size(self) -> int:
        return len(self.data)

    def intersection(self, set2: set) -> set:
        ans = set()
        set1 = list(set2)
        for elmt in set1:
            if (elmt in self.data):
                ans.add(elmt)
        return ans

    def union(self, set2: set) -> set:
        ans = set()
        set1 = list(set2)
        for elmt in set1:
            ans.add(elmt)
        return ans

    def difference(self, set2: set) -> set:
        ans = self.data.copy()
        set1 = list(set2)
        for elmt in set1:
            ans.remove(elmt)
        return ans

    def subset(self, set2: set) -> set:
        return self.data.issubset(set2)

    def display(self) -> None:
        print(self.data)


def input_set() -> set:
    ans = set()
    n = int(input("Enter number of elements in set:"))
    for i in range(n):
        ans.add(int(input(f"Enter element {i+1}:")))
    return ans


def main() -> None:
    s1 = sets()
    choice = 1
    while (choice != 0):
        print("MENU")
        print("1.Add new element")
        print("2.Remove element")
        print("3.Search element")
        print("4.Display Size of Set")
        print("5.Intersection of Sets")
        print("6.Union of Sets")
        print("7.Difference of Sets")
        print("8.Check if subset of Set")
        print("0. exit")
        choice = int(input("Enter Your Choice:"))
        match (choice):
            case (1):
                n = int(input("Enter Number to add:"))
                s1.add(n)
                print("Element added sucessfully")
            case (2):
                n = int(input("Enter Number to Remove:"))
                if (s1.remove(n)):
                    print("Element Removed sucessfully")
                else:
                    print("Element Not present in set")
            case (3):
                n = int(input("Enter Number to Remove:"))
                if (s1.contains(n)):
                    print("Element Removed sucessfully")
                else:
                    print("Element Not present in set")
            case (4):
                print("Size of the set is ", s1.size())
            case (5):
                s = input_set()
                print("Intersection of sets is ", s1.intersection(s))
            case (6):
                s = input_set()
                print("Union of sets is ", s1.union(s))
            case (7):
                s = input_set()
                print("Difference of sets is ", s1.difference(s))
            case (8):
                s = input_set()
                if (s1.subset(s)):
                    print("Set is Subset")
                else:
                    print("Set is Not subset")
            case (0):
                print("Thank You!")
            case default:
                print("Invalid Choice")


if __name__ == "__main__":
    main()
