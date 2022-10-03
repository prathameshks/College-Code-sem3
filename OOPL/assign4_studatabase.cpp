/*
Develop a program in C++ to create a database of student’s information system containing the following information: 
Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. 
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
*/
#include<iostream>

using namespace std;


class information{
	string name,dob,bloodgrp,mob_num,address,dl_num,;
	
	public
	information(){
		name = "ABC";
		dob = "dd/mm/yyyy";
		bloodgrp = "X+";
		mob_num = "1234567890";
		address = "Pune, Maharashtra, India";
		dl_num = "MH01/0123/0123456";
	}
	information(const information &obj){
		
	}
	friend class student;
};
class student{
	int roll_no;
	string class,remark;
	char div;
};


int main(){
	student *stuname[100];
	return 0;
}
