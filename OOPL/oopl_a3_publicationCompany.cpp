/*
Imagine a publishing company which does marketing for book and audio cassette versions.
Create a class publication that stores the title (a string) and price (type float) of publications.
From this class derive two classes: book which adds a page count (type int) and tape which
adds a playing time in minutes (type float).
Write a program that instantiates the book and tape class, allows user to enter data and
displays the data members. If an exception is caught, replace all the data member values with
zero values.
*/
#include<iostream>
#include <vector>
using namespace std;

class publication{
	protected:
	string title;
	float price;
	
	public:
	publication(){
		title = "";
		price = 0;
	}
	publication(string title, float price){
	this-> title = title;
	this-> price = price;
	}
	
};


class book : public publication{
	private:
	int	page_count;
	public:
	book(){
		page_count = 0;
	}
	book(string title,float price,int page_count):publication(title, price){
		this->page_count = page_count;
	}
	void set_data(){
		cout<<"Enter title of the book:";
		cin.ignore();
		getline(cin,title);
		
		cout<<"Enter price of the book:";
		cin>>price;
		
		cout<<"Enter page count of the book:";
		cin>>page_count;		
		
	}
	void display_data(){
		cout<<"Title of the book is "<<title<<endl;
		
		cout<<"Price of the book is "<<price<<endl;
		
		cout<<"Number of pages of the book are "<<page_count<<endl;		
		
	}
	
};

class tape : public publication{
	private:
	float playing_time;
	public:
	tape(){
		playing_time = 0;
	}
	tape(string title,float price,float playing_time):publication(title, price){
		this->playing_time = playing_time;
	}
	void set_data(){
		cout<<"Enter title of the tape:";
		cin.ignore();
		getline(cin,title);
		
		cout<<"Enter price of the tape:";
		cin>>price;
		
		cout<<"Enter playing time of the tape:";
		cin>>playing_time;		
		
	}
	void display_data(){
		cout<<"Title of the tape is "<<title<<endl;
		
		cout<<"Price of the tape is "<<price<<endl;
		
		cout<<"Playing time of the tape is "<<playing_time<<endl;		
		
	}
	
	
};

int main(){
	vector<book*> book_record;
	vector<tape*> tape_record;
	bool loop_control = true;
	int choice;
	book *book_rec;
	tape *tape_rec;
	int i;
	
	while(loop_control){
		cout<<"\n---MENU---"<<endl;
		cout<<"1. Add new Book"<<endl;
		cout<<"2. Add new Tape"<<endl;
		cout<<"3. Display all Book data"<<endl;
		cout<<"4. Display all Tape data"<<endl;
		cout<<"5. Display count of Books and Tape"<<endl;
		cout<<"6. Exit."<<endl;
		cout<<"Enter your Choice:";
		cin>>choice;
		switch (choice){
			case 1:
				book_rec = new book;
				book_rec->set_data();
				book_record.push_back(book_rec);
				cout<<"Book record added sucessfully :)"<<endl;
				break;
			case 2:
				tape_rec = new tape;
				tape_rec->set_data();
				tape_record.push_back(tape_rec);
				cout<<"Tape record added sucessfully :)"<<endl;
				break;
			case 3:
				for(i=0;i<book_record.size();i++){
					cout<<"\nRecord number :"<<i+1<<endl;
					book_rec = book_record.at(i);
					book_rec->display_data();
				}
				break;
			case 4:
				for(i=0;i<tape_record.size();i++){
					cout<<"\nRecord number :"<<i+1<<endl;
					tape_rec = tape_record.at(i);
					tape_rec->display_data();
				}
				break;
			case 5:
				cout<<"Total Book records :"<<book_record.size()<<endl;
				cout<<"Total Tape records :"<<tape_record.size()<<endl;
				
				break;
			case 6:
				loop_control = false;
				cout<<"Thank You"<<endl;
				break;
			
			default:
				break;
		}
	}
	return 0;
}
