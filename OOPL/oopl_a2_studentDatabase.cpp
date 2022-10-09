/*
Develop a program in C++ to create a database of student’s information system containing the following information:
Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other.
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
*/
#include <iostream>
#include<iomanip>

using namespace std;

class information
{
	string name, dob, bloodgrp, mob_num, address, dl_num;

public:
	information()
	{
		name = "ABC";
		dob = "dd/mm/yyyy";
		bloodgrp = "X+";
		mob_num = "1234567890";
		address = "Pune, Maharashtra, India";
		dl_num = "MH01/0123/0123456";
	}
	information(const information &obj)
	{
		this->name = obj.name;
		this->dob = obj.dob;
		this->bloodgrp = obj.bloodgrp;
		this->mob_num = obj.mob_num;
		this->address = obj.address;
		this->dl_num = obj.dl_num;
	}
	information(string name,string dob,string bloodgrp,string mob_num,string address,string dl_num){
		this->name = name;
		this->dob = dob;
		this->bloodgrp = bloodgrp;
		this->mob_num = mob_num;
		this->address = address;
		this->dl_num = dl_num;
	}
	friend class student;
};

class student
{
	int roll_no;
	string class_name, remark;
	char div;
	static int student_count;

public:
	student()
	{
		roll_no = 0;
		class_name = "SE Comp";
		div = 'A';
		remark = "";
		student_count++;
	}
	student(int roll_no, string class_name, char div, string remark = "")
	{
		this->class_name = class_name;
		this->div = div;
		this->remark = remark;
		this->roll_no = roll_no;

		student_count++;
	}
	student(const student *stu){
		this->class_name = stu->class_name;
		this->div = stu->div;
		this->remark = stu->remark;
		this->roll_no = stu->roll_no;

		student_count++;
	}
	~student()
	{
		student_count--;
	}
	inline static int get_student_count()
	{
		return student_count;
	}
	void display_details(const information *info){
		cout<<"Student Name: "<<info->name<<endl;
		cout<<"Roll No.: "<<roll_no<<endl;
		cout<<"Class: "<<class_name<<endl;
		cout<<"Division :"<<div<<endl;
		cout<<"Date of Birth: "<<info->dob<<endl;
		cout<<"Blood Group: "<<info->bloodgrp<<endl;
		cout<<"Mobile Number: "<<info->mob_num<<endl;
		cout<<"DL Number: "<<info->dl_num<<endl;
		cout<<"Adderss of Student: "<<info->address<<endl;
		cout<<"Remarks(if any): "<<remark<<endl;
	}
};

int student::student_count = 0;

int main()
{
	student *stu_list[100];
	information *stu_info[100];
	bool while_control = true;
	while (while_control)
	{
		// cout<<"---- MENU ----"<<endl;
		// cout<<"1. Add New Student"<<endl;
		// cout<<"2. Display"<<endl;
		break;
	}
	
	// cout << student::get_student_count() << endl;
	// stu_list[0] = new student(1,"SE Comp",'A');
	// stu_info[0] = new information;
	// stu_list[1] = new student(stu_list[0]);
	// stu_list[0]->display_details(stu_info[0]);
	// stu_list[1]->display_details(stu_info[0]);
	string a= "Hello i am prathamesh sable";
	//for setw #include<iomanip>

	cout<<setw(10)<<a.substr(0,10)<<endl;
	return 0;
}