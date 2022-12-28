/*
Develop a program in C++ to create a database of student's information system
containing the following information: Name, Roll number, Class, Division, Date
of Birth, Blood group, Contact address, Telephone number, Driving license no.
and other. Construct the database with suitable member functions. Make use of
constructor, default constructor, copy constructor, destructor, static member
functions, friend class, this pointer, inline code and dynamic memory allocation
operators-new and delete as well as exception handling.
*/

/*
+--------------------------------------------------+
| ▀█▀ █▄  █ █▀▀█ █▀▀█ █▀▄▀█ █▀█ █    █▀▀ ▀▀█▀▀ █▀▀ |
|  █  █ █ █ █    █  █ █ █ █ █▄█ █    █▀    █   █▀  |
| ▄█▄ █  ▀█ █▄▄█ █▄▄█ █   █ █   █▄▄█ █▄▄   █   █▄▄ |
+--------------------------------------------------+
*/

#include <iostream>
using namespace std;

class info {
   private:
    string name;
    string dob;
    string b_grp;
    string tel_no;
    string address;
    string dl_no;

   public:
    info();
    info(info &obj);
    info(string name, string dob, string b_grp, string tel_no, string address,
         string dl_no);
};

info::info() {
    name = "XYZ";
    dob = "11/11/1111";
    b_grp = "AB+";
    tel_no = "1234567890";
    address = "ABC Streat,X town,111111";
    dl_no = "MH12/12345/1234";
}

info::info(info &obj) {
    this->name = obj.name;
    this->dob = obj.dob;
    this->b_grp = obj.b_grp;
    this->tel_no = obj.tel_no;
    this->address = obj.address;
    this->dl_no = obj.dl_no;
}

info::info(string name, string dob, string b_grp, string tel_no, string address,
           string dl_no) {
    this->name = name;
    this->dob = dob;
    this->b_grp = b_grp;
    this->tel_no = tel_no;
    this->address = address;
    this->dl_no = dl_no;
}

class student {
   private:
    int roll;
    string cls;
    int div;
    string remark;
    static int count;

   public:
    student();
    student(student &stu);
    student(int roll, string cls, int div, string remark);
    ~student();
};

student::student() {
    roll = 0;
    cls = "SE Comp";
    div = 1;
    remark = "NA";
}

student::student(student &stu) {
    this->roll = stu.roll;
    this->cls = stu.cls;
    this->div = stu.div;
    this->remark = stu.remark;
    count++;
}

student::student(int roll, string cls, int div, string remark) {
    this->roll = roll;
    this->cls = cls;
    this->div = div;
    this->remark = remark;
    count++;
}

student::~student() { count--; }

int main() { return 0; }