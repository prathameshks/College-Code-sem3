/*
Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
*/
#include <iostream>
using namespace std;

template <class type>
void swap(type *n1, type *n2)
{
    type temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

template <class type>
void Selection_sort(type arr[], int length)
{
    // minimun index variable
    int min_ind;
    int j, i;
    type temp;

    // for loop for index up to n-1
    for (i = 0; i < length - 1; i++)
    {
        min_ind = i;
        for (j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min_ind])
                min_ind = j;
        }
        // swap values
        temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
}

template <class type>
void display(type *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    int arr1[10];
    float arr2[10];

    cout << "Enter Number of elements in Integer Array:";
    cin >> n;
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cout << "Array Entered is " << endl;
    display<int>(arr1, n);
    // sorting array
    Selection_sort<int>(arr1, n);

    cout << "Array After sorting is " << endl;
    display<int>(arr1, n);


    cout << "Enter Number of elements in Float Array:";
    cin >> n;
    cout << "Enter elements of array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    cout << "Array Entered is " << endl;
    display<float>(arr2, n);
    // sorting array
    Selection_sort<float>(arr2, n);

    cout << "Array After sorting is " << endl;
    display<float>(arr2, n);
    
    return 0;
}