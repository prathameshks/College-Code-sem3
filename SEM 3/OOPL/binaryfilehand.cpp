#include <fstream>
#include <iostream>
using namespace std;

// global file for employee and student
fstream file1, file2;

// student class
class Student {
   public:
    int rollno;
    char stuname[20], address[30];
    void setdata() {
        cout << "Enter Student Roll No:";
        cin >> rollno;
        cout << "Enter Student Name:";
        cin >> stuname;
        cout << "Enter Student Address:";
        cin >> address;
    }
    void diaplay() {
        cout << rollno << " - " << stuname << " - " << address << endl;
    }
};

// employee class
class Employee {
   public:
    int empid;
    char empname[20];
    float empsal;
    void setdata() {
        cout << "Enter Employee ID:";
        cin >> empid;
        cout << "Enter Employee Name:";
        cin >> empname;
        cout << "Enter Employee Salary:";
        cin >> empsal;
    }
    void diaplay() {
        cout << empid << " - " << empname << " - " << empsal << endl;
    }
};

// Employee functions
void writeRec(Employee emp) {
    file1.open("EmployeeData.dat", ios::binary | ios::out);
    file1.write((char*)&emp, sizeof(emp));
    cout << "Data Written Sucessfully" << endl;
    file1.close();
}
void appendRec(Employee emp) {
    file1.open("EmployeeData.dat", ios::binary | ios::out | ios::app);
    file1.write((char*)&emp, sizeof(emp));
    cout << "Data Written Sucessfully" << endl;
    file1.close();
}

void readEmpRec() {
    Employee emp;
    file1.open("EmployeeData.dat", ios::binary | ios::in);
    while (file1) {
        if (file1.read((char*)&emp, sizeof(emp))) {
            emp.diaplay();
        }
    }
    cout << "End of File" << endl;
    file1.close();
}

// Student functions
void writeRec(Student stu) {
    file2.open("StudentData.dat", ios::binary | ios::out);
    file2.write((char*)&stu, sizeof(stu));
    cout << "Data Written Sucessfully" << endl;
    file2.close();
}
void appendRec(Student stu) {
    file2.open("StudentData.dat", ios::binary | ios::out | ios::app);
    file2.write((char*)&stu, sizeof(stu));
    cout << "Data Written Sucessfully" << endl;
    file2.close();
}

void readStuRec() {
    Student stu;
    file2.open("StudentData.dat", ios::binary | ios::in);
    while (file2) {
        if (file2.read((char*)&stu, sizeof(stu))) {
            stu.diaplay();
        }
    }
    cout << "End of File" << endl;
    file2.close();
}

int main() {
    bool loop_control = true;
    int ch;
    Employee emp;
    Student stu;

    while (loop_control) {
        cout << "Menu \n1. Write Employee Rec\n2. Append Employee Rec\n3. Read All Employee Rec" << endl;
        cout << "4. Write Student Rec\n5. Append Student Rec\n6. Read All Student Rec\n7. Exit" << endl;
        cout << "Enter your choice";
        cin >> ch;
        switch (ch) {
            case 1:
                emp.setdata();
                writeRec(emp);
                break;

            case 2:
                emp.setdata();
                appendRec(emp);
                break;

            case 3:
                readEmpRec();
                break;

            case 4:
                stu.setdata();
                writeRec(stu);
                break;

            case 5:
                stu.setdata();
                appendRec(stu);
                break;

            case 6:
                readStuRec();
                break;

            case 7:
                loop_control = false;
                cout << "Thank you" << endl;
                break;

            default:
                cout << "Enter a valid choice" << endl;
                break;
        }
    }

    return 0;
}