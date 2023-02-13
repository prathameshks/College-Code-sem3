#include <iostream>
using namespace std;


void fun1(int *a){
    *a = 13;
    cout<<a<<endl;
}
void fun2(int &a){
    a = 12;
    cout<<&a<<endl;
}


int main(){
    // int b = 5;
    // fun1(&b);
    // cout<<b<<endl;
    // fun2(b);
    // cout<<b<<endl;
    return 0;
}