#include<iostream>
using namespace std;

void mergesort( int arr1[],int size1,int arr2[],int size2,int arr[],int size)
{
    int i=0,j=0,k=0;
    while(i<size1 && j<size2)
    {
        if(arr1[i]<arr2[j])
        {
            arr[k]=arr1[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=arr2[j];
            k++;
            j++;
        }
    }
    while(i<size1)
    {
        arr[k]=arr1[i];
        k++;
        i++;
    }
    while(j<size2)
    {
        arr[k]=arr2[j];
        k++;
        j++;
    }
}
void printarr(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr1[5]={1,3,5,7,9};
    int size1=sizeof(arr1)/sizeof(int);
    printarr(arr1,size1);
    int arr2[5]={2,4,6,8,10};
    int size2=sizeof(arr2)/sizeof(int);
    printarr(arr2,size2);
    int size=size1+size2;
    int arr[10];
    mergesort(arr1,size1,arr2,size2,arr,size);
    //printarr(arr,size);
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}