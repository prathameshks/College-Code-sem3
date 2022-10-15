/*
Develop a program in C++ to create a database of student’s information system containing the following information:
Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other.
Construct the database with suitable member functions. Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
#define max 100 // defining size of max array

using namespace std;
class student;
class information;

class information
{
	string name, dob, bloodgrp, mob_num, address, dl_num;

public:
	information() // default constructor
	{
		name = "ABC";
		dob = "dd/mm/yyyy";
		bloodgrp = "X+";
		mob_num = "1234567890";
		address = "Pune, Maharashtra, India";
		dl_num = "MH01/0123/0123456";
	}
	information(const information &obj) // copy constructor
	{
		this->name = obj.name;
		this->dob = obj.dob;
		this->bloodgrp = obj.bloodgrp;
		this->mob_num = obj.mob_num;
		this->address = obj.address;
		this->dl_num = obj.dl_num;
	}
	information(string name, string dob, string bloodgrp, string mob_num, string address, string dl_num) // constructor
	{
		this->name = name;
		this->dob = dob;
		this->bloodgrp = bloodgrp;
		this->mob_num = mob_num;
		this->address = address;
		this->dl_num = dl_num;
	}
	void edit(int index, string list[])
	{
		cout << "Enter new " << list[index] << ":";
		cin.ignore();
		switch (index)
		{
		case 1:
			getline(cin, name);
			break;
		case 5:
			getline(cin, dob);
			break;
		case 6:
			getline(cin, bloodgrp);
			break;
		case 7:
			getline(cin, mob_num);
			break;
		case 8:
			getline(cin, dl_num);
			break;
		case 9:
			getline(cin, address);
			break;
		default:
			break;
		}
	}
	friend class student;
	friend void display_all(student *s_list[], information *s_info[]);
	friend void save_data(student *s_list[], information *s_info[]);
};

class student
{
	int roll_no;
	string class_name, remark;
	char div;
	static int student_count;

public:
	student() // default constructor
	{
		roll_no = 0;
		class_name = "SE Comp";
		div = 'A';
		remark = "";
		student_count++;
	}
	student(int roll_no, string class_name, char div, string remark = "") // constructor
	{
		this->class_name = class_name;
		this->div = div;
		this->remark = remark;
		this->roll_no = roll_no;

		student_count++;
	}
	student(const student *stu) // copy constructor
	{
		this->class_name = stu->class_name;
		this->div = stu->div;
		this->remark = stu->remark;
		this->roll_no = stu->roll_no;

		student_count++;
	}
	~student() // destructor
	{
		student_count--;
	}

	// friend functions
	friend int search_stu(int roll, student *s_list[]);
	friend void display_all(student *s_list[], information *s_info[]);
	friend void save_data(student *s_list[], information *s_info[]);

	inline static int get_student_count()
	{
		return student_count;
	}
	void display_details(const information *info)
	{
		cout << "Student Name: " << info->name << endl;
		cout << "Roll No.: " << roll_no << endl;
		cout << "Class: " << class_name << endl;
		cout << "Division :" << div << endl;
		cout << "Date of Birth: " << info->dob << endl;
		cout << "Blood Group: " << info->bloodgrp << endl;
		cout << "Mobile Number: " << info->mob_num << endl;
		cout << "DL Number: " << info->dl_num << endl;
		cout << "Adderss of Student: " << info->address << endl;
		cout << "Remarks(if any): " << remark << endl;
	}
	void edit(information *info)
	{
		int choice;
		string value;
		string choices[11] = {"", "Student Name", "Roll No.", "Class", "Division", "Date of Birth", "Blood Group", "Mobile Number", "DL Number", "Adderss of Student", "Remarks"};
		cout << "What you Want to Edit?" << endl;
		for (int j = 1; j <= 10; j++)
			cout << j << ". " << choices[j] << endl;
		cout << "11. Cancel" << endl;
		cout << "Enter Your Choice:";
		cin >> choice;
		if (choice <= 0 or choice > 11)
		{
			cout << "Invalid Choice, Canceling Edit." << endl;
			return;
		}
		if (choice == 11)
		{
			cout << "Canceling Edit." << endl;
			return;
		}
		if (choice == 3 or choice == 10)
		{
			cout << "Enter new " << choices[choice] << ":";
			cin.ignore();
			getline(cin, value);
			if (choice == 3)
			{
				class_name = value;
			}
			else
			{
				remark = value;
			}
		}
		else if (choice == 4)
		{
			cout << "Enter new division:";
			cin >> div;
		}
		else if (choice == 2)
		{
			cout << "Enter new Roll no:";
			cin >> roll_no;
		}
		else
		{
			info->edit(choice, choices);
		}
	}
};

int student::student_count = 0;

// print row function
template <class i, class c>
void row_print(i sr, string name, i roll, string cls, c div, string dob, string bgrp, string mobile, string dlno, string add, string remark, char sep = '|')
{
	cout << sep << setw(5) << right << sr << sep;
	cout << setw(15) << left << name.substr(0, 15) << sep;
	cout << setw(7) << right << roll << sep;
	cout << setw(9) << left << cls.substr(0, 9) << sep;
	cout << setw(3) << left << div << sep;
	cout << setw(10) << left << dob.substr(0, 10) << sep;
	cout << setw(9) << left << bgrp.substr(0, 9) << sep;
	cout << setw(13) << left << mobile.substr(0, 13) << sep;
	cout << setw(17) << left << dlno.substr(0, 17) << sep;
	cout << setw(20) << left << add.substr(0, 20) << sep;
	cout << setw(15) << left << remark.substr(0, 15) << sep << endl;
}

// display all data
void display_all(student *s_list[], information *s_info[])
{
	row_print<string, string>("-----", "---------------", "-------", "---------", "---", "----------", "---------", "-------------", "-----------------", "--------------------", "---------------", '+');
	row_print<string, string>("Sr No", "Student Name", "Roll No", "Class", "Div", "Birth Date", "Blood Grp", "Mobile Number", "DL Number", "Adderss of Student", "Remarks(if any)");
	row_print<string, string>("-----", "---------------", "-------", "---------", "---", "----------", "---------", "-------------", "-----------------", "--------------------", "---------------", '+');
	try
	{
		for (int i = 0; i < student::get_student_count(); i++)
		{
			row_print<int, char>(i + 1, s_info[i]->name, s_list[i]->roll_no, s_list[i]->class_name, s_list[i]->div, s_info[i]->dob, s_info[i]->bloodgrp, s_info[i]->mob_num, s_info[i]->dl_num, s_info[i]->address, s_list[i]->remark);
		}
	}
	catch (exception e)
	{
		cout << e.what();
	}
	row_print<string, string>("-----", "---------------", "-------", "---------", "---", "----------", "---------", "-------------", "-----------------", "--------------------", "---------------", '+');
}

void add_student(int index, student *s_list[], information *s_info[])
{
	string name, dob, bloodgrp, mob_num, address, dl_num;
	int roll_no;
	string class_name, remark;
	char div;
	cin.ignore();
	cout << "Enter Student Details below" << endl;
	cout << "Name:";
	getline(cin, name);
	cout << "DOB:";
	getline(cin, dob);
	cout << "Blood Group:";
	getline(cin, bloodgrp);
	cout << "Mobile Number:";
	getline(cin, mob_num);
	cout << "Address:";
	getline(cin, address);
	cout << "DL Number:";
	getline(cin, dl_num);

	s_info[index] = new information(name, dob, bloodgrp, mob_num, address, dl_num);

	cout << "Class:";
	getline(cin, class_name);
	cout << "Division:";
	cin >> div;
	cout << "Roll Number:";
	cin >> roll_no;
	cout << "Remarks:";
	cin.ignore();
	getline(cin, remark);

	s_list[index] = new student(roll_no, class_name, div, remark);
}

int search_stu(int roll, student *s_list[])
{
	for (int i = 0; i < student::get_student_count(); i++)
	{
		if (s_list[i]->roll_no == roll)
		{
			return i;
		}
	}
	return -1;
}

void save_data(student *s_list[], information *s_info[])
{
	ofstream data_file("StudentData.txt");
	char sep = '$';
	try
	{
		for (int i = 0; i < student::get_student_count(); i++)
		{
			// add record to file
			data_file << s_info[i]->name << sep << s_list[i]->roll_no << sep << s_list[i]->class_name << sep << s_list[i]->div << sep << s_info[i]->dob << sep << s_info[i]->bloodgrp << sep << s_info[i]->mob_num << sep << s_info[i]->dl_num << sep << s_info[i]->address << sep << s_list[i]->remark << endl;
		}
	}
	catch (exception e)
	{
		cout << e.what();
	}
	data_file.close();
}

void load_data(int *current, student *s_list[], information *s_info[])
{
	// checking if file exists
	ifstream data_file("StudentData.txt");
	if (data_file)
	{
		cout << "Loading Previous Data, Please Wait..." << endl;
	}
	else
	{
		// file doesn't exist
		return;
	}

	char sep = '$';
	string line;
	string all_data[10] = "";
	int last, line_index;
	while (data_file.eof() == 0)
	{
		getline(data_file, line);
		if (line == "")
		{
			// skip empty line
			continue;
		}

		last = 0;
		line_index = 0;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == sep)
			{
				all_data[line_index] = line.substr(last, i - last);
				last = i + 1;
				line_index++;
			}
		}
		all_data[line_index] = line.substr(last, line.size() - last);

		// passign values to function for object creation
		s_info[*current] = new information(all_data[0], all_data[4], all_data[5], all_data[6], all_data[8], all_data[7]);
		s_list[*current] = new student(stoi(all_data[1]), all_data[2], all_data[3][0], all_data[9]);
		(*current)++;
	}
	data_file.close();
	cout << "Imported " << *current << " records." << endl;
}

int main()
{
	// list of pointers for data
	student *stu_list[max];
	information *stu_info[max];
	bool while_control = true;
	int srch, ind, choice, current = 0;

	// load past data
	load_data(&current, stu_list, stu_info);

	while (while_control)
	{
		cout << "-------- MENU --------" << endl;
		cout << "  1. Add New Student" << endl;
		cout << "  2. Display All Students" << endl;
		cout << "  3. Search and Display Student Record" << endl;
		cout << "  4. Delete Student Record" << endl;
		cout << "  5. Edit Student Record" << endl;
		cout << "  6. Save" << endl;
		cout << "  7. Save & Exit" << endl;
		cout << "Enter your choice:";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			if (current < 100) // condition to check limit
			{
				add_student(current, stu_list, stu_info);
				current++;
			}
			else
			{
				cout << "Can't add student record, Because Reached the limit of records." << endl;
			}
			break;
		case 2:
			cout << "Found " << student::get_student_count() << " records." << endl;
			if (student::get_student_count() != 0)
			{
				display_all(stu_list, stu_info);
			}
			break;
		case 3:
			cout << "Enter Roll number to Search(Enter 0 display list):";
			cin >> srch;
			if (srch == 0)
			{
				display_all(stu_list, stu_info);
				cout << "Enter Roll number to Search:";
				cin >> srch;
			}

			ind = search_stu(srch, stu_list);
			if (ind == -1)
				cout << "No Record Found" << endl;
			else
			{
				cout << "\tRecord Found." << endl;
				stu_list[ind]->display_details(stu_info[ind]);
			}

			break;
		case 4:
			cout << "Enter Roll number to Delete(Enter 0 display list):";
			cin >> srch;
			if (srch == 0)
			{
				display_all(stu_list, stu_info);
				cout << "Enter Roll number to Delete:";
				cin >> srch;
			}

			ind = search_stu(srch, stu_list);
			if (ind == -1)
				cout << "No Record Found to Delete" << endl;
			else
			{
				delete stu_list[ind];
				delete stu_info[ind];
				stu_list[ind] = stu_list[current - 1];
				stu_info[ind] = stu_info[current - 1];
				current--;
				cout << "Record Deleted Sucessfully." << endl;
			}
			break;
		case 5:
			cout << "Enter Roll number to Edit(Enter 0 display list):";
			cin >> srch;
			if (srch == 0)
			{
				display_all(stu_list, stu_info);
				cout << "Enter Roll number to Edit:";
				cin >> srch;
			}

			ind = search_stu(srch, stu_list);
			if (ind == -1)
				cout << "No Record Found to Edit" << endl;
			else
			{
				stu_list[ind]->edit(stu_info[ind]);
				cout << "Record Edited Sucessfully." << endl;
			}
			break;
		case 6:
			save_data(stu_list, stu_info);
			cout << "Data Saved Sucessfully" << endl;
			break;

		case 7:
			save_data(stu_list, stu_info);
			cout << "Thank you for using Application:)" << endl;
			while_control = false;
			break;

		default:
			cout << "Enter a Valid Choice." << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}

/*
yash jadhav
13/04/2003
A+
1234567890
kutruj maha india
mh14/1452/278122
se comp2
b
13
rem

*/