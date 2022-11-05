#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class file{
    public:
    int i=0;
    string str1,str2;
    void write(){
        ofstream obj1;
        obj1.open("xyz.txt");
        cout<<"ENTER THE DATA IN THE FILE: "<<endl;
        getline(cin,str1);
        obj1<<str1;
        obj1.close();
        cout<<"CLOSING THE FILE!!!!!"<<endl;
    }
    void read(){
        ifstream obj2("xyz.txt");
        // obj2>>str2;
        cout<<"YOUR READ DATA IS :"<<endl;
        while(getline(obj2,str2)){
            cout<<str2;
        }
        obj2.close();
    }
};
int main(){
    file obj3;
    obj3.write();
    obj3.read();
    return 0;
}