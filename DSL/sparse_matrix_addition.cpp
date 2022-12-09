#include<iostream>
using namespace std;

void display_sparse(int a[21][3],int elmt){
    cout<<"r "<<"c " <<"Elmt"<<endl;
    for (int i =0;i<=elmt;i++){
        cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<endl;
    }
}

void add(int a[11][3],int b[11][3],int c[21][3]){
    int i=1;
    int j=1;
    int k=0;
    if (a[0][0] != b[0][0] or a[0][1] != b[0][1]){
        cout<<"Adiition not possiable"<<endl;
        return;
    }
    while(i<=a[0][2] && j<=b[0][2]){
        if(a[i][0] == b[j][0]){
            if(a[i][1] == b[j][1]){
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2] + b[j][2];
                i++;
                j++;
                k++;
            }else if(a[i][1]<b[j][1]){
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k++;
                j++;
            }else{
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k++;
                i++;
            }

        }else if(a[i][0]<b[j][0]){
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k++;
            i++;
        }else{
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k++;
            j++;
        }
    }
    while(i<=a[0][2]){
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        k++;
        i++;
    }
    while(j<=b[0][2]){
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        k++;
        j++;
    }
    c[0][0] = a[0][0];
    c[0][1] = a[0][1];
    c[0][2] = k-1;
}




// Driver code
int main()
{
    int a[11][3]={
        {4, 4, 5},
        {1, 2, 10},
        {1, 4, 12},
        {3, 3, 5},
        {4, 1, 15},
        {4, 2, 12}
    };

    int b[11][3] ={
        {4,4,5},
        {1,3,8},
        {2,4,23},
        {3,3,9},
        {4,1,20},
        {4,2,25}
    };
    int c[21][3];
    add(a,b,c);
    display_sparse(a,a[0][2]);
    display_sparse(b,b[0][2]);
    display_sparse(c,c[0][2]);
    
    return 0;
}