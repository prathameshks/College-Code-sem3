#include<iostream>
#include <string>
using namespace std;

class Complex{
	public:
	float real,imag;
	
	Complex(){
		real = 0;
		imag = 0;
	}
	Complex(float real,float imag){
		this->real = real;
		this->imag = imag;
	}
	
	void disp(){
		cout<<real<<"+"<<imag<<"i"<<endl;
		
	}
	
	Complex operator+(Complex num2){
		Complex res;
		res.real = (real + num2.real);
		res.imag = (imag + num2.imag);
		return res;
	}
	
	Complex operator*(Complex num2){
		Complex res;
		res.real = ((real * num2.real)-(imag * num2.imag));
		res.imag = ((real * num2.imag)+(imag * num2.real));
		return res;
	}
	
	friend ostream &operator<<(ostream &object,Complex &num);
	friend istream &operator>>(istream &object,Complex &num);
	
};

ostream &operator<<(ostream &object,Complex &num){
	//object<<"working"<<endl;
	if (num.imag < 0){
	object<<num.real<<num.imag<<"i"<<endl;
	}else{
	object<<num.real<<"+"<<num.imag<<"i"<<endl;
	}
	return object;
}

istream &operator>>(istream &object,Complex &num){
	//object<<"working"<<endl;
	string str;
	getline(object,str);
	cout<<str<<"%"<<endl;
	
	//object>>num.real>>num.imag;
	int i,op;
	n = sizeof(str);
	for(i = 0;i<n;i++){
		if ((str[i] == '+')||(str[i] == '-')){
			num.real = stof(str.substr(0,i));
			op=i;
		}else if(str[i] == 'i'){
			num.imag = stof(str.substr(op,i));
		}else if(str[i] == ' '){
			num.real = stof(str.substr(0,i));
			num.imag = stof(str.substr(i+1,n+1));
			break;
		}
	}
	return object;
}

/*
istream &operator>>(istream &object,Complex &num){
	//object<<"working"<<endl;
	object>>num.real>>num.imag;
	
	return object;
}
*/

int main(){
	//Complex c1(3,-9);
	//Complex c2(1,2);
	//c1.disp();
	//c2.disp();
	Complex c1,c2;
	cin>>c1>>c2;
	Complex ans = c1*c2;
	//ans.disp();
	cout<<ans;
	return 0;
}
