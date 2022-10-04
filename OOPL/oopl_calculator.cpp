#include<iostream>
using namespace std;

double addition(double num1,double num2){
	return num1+num2;
}
double subtraction(double num1,double num2){
	return num1-num2;
}
double multiplication(double num1,double num2){
	return num1*num2;
}
double division(double num1,double num2){
	return num1/num2;
}

int main(){
	double a,b;
	bool while_var = true;
	int choice;
	double result=0;
	bool show_exit;
	char ch;
	while(while_var){
		cout<<"Enter first number :";
		cin>>a;
		cout<<"Enter second number :";
		cin>>b;
		cout<<"\nWhich operartion do you want to perform?"<<endl;
		cout<<"1. Addition \n2. Subtraction \n3. Multiplication \n4. Division \n5. All"<<endl;
		cout<<"Enter your choice :";
		cin>>choice;
		show_exit = true;
		switch (choice){
			case 1:
				result = addition(a,b);
				cout<<"Addition of "<<a<<" & "<<b<<" is "<<result<<endl;
				break;
			case 2:
				result = subtraction(a,b);
				cout<<"Subtraction of "<<a<<" & "<<b<<" is "<<result<<endl;
				break;
			case 3:
				result = multiplication(a,b);
				cout<<"Multiplication of "<<a<<" & "<<b<<" is "<<result<<endl;
				break;
			case 4:
				result = division(a,b);
				cout<<"Division of "<<a<<" & "<<b<<" is "<<result<<endl;
				break;
			case 5:
				result = addition(a,b);
				cout<<"Addition of "<<a<<" & "<<b<<" is "<<result<<endl;
				result = subtraction(a,b);
				cout<<"Subtraction of "<<a<<" & "<<b<<" is "<<result<<endl;
				result = multiplication(a,b);
				cout<<"Multiplication of "<<a<<" & "<<b<<" is "<<result<<endl;
				result = division(a,b);
				cout<<"Division of "<<a<<" & "<<b<<" is "<<result<<endl;
				break;
			default:
				cout<<"Enter a valid choice :)"<<endl;
				show_exit = false;
		}
		if(show_exit){
			cout<<"Do you want to Exit(y/n) :";
			cin>>ch;
			if (ch == 'y'){
				while_var = false;
			}
		}
		
	}
	return 0;
}