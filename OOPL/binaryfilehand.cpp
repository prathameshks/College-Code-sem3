#include <fstream>
#include <iostream>
using namespace std;

// global file for employee
fstream file;

class Employee {
   public:
    int empid;
    char empname[20];
    float empsal;
    Employee() {}
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

void writeRec(Employee emp) {
    file.open("EmployeeData.dat", ios::binary | ios::out);
    file.write((char*)&emp, sizeof(emp));
    cout << "Data Written Sucessfully" << endl;
    file.close();
}
void appendRec(Employee emp) {
    file.open("EmployeeData.dat", ios::binary | ios::out | ios::app);
    file.write((char*)&emp, sizeof(emp));
    cout << "Data Written Sucessfully" << endl;
    file.close();
}
void readRec() {
    Employee emp;
    file.open("EmployeeData.dat", ios::binary | ios::in);
    while (file) {
        if (file.read((char*)&emp, sizeof(emp))) {
            emp.diaplay();
        }
    }

    cout << "End of File" << endl;
    file.close();
}
int main() {
    bool loop_control = true;
    int ch;
    Employee emp;

    while (loop_control) {
        cout << "Menu 1. Write 2. Append 3. Read All 4. Exit" << endl;
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
                readRec();
                break;

            case 4:
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