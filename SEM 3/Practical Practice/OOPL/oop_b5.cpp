/*
Write a function template for selection sort that inputs, sorts and outputs an
integer array and a float array.
*/
#include <iostream>
using namespace std;

template <typename t1>
void selection_sort(t1 arr[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            t1 temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

template <typename t1>
void display(t1 arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        cout << arr[i] << ",";
    }
    cout << arr[n - 1] << "\n";
}

int main() {
    int a[10] = {1223, 3423, 4, 54, 7658, 678, 64, 534, 2, 42};
    double b[10] = {12.23, 34.23, 4, 5.4, 76.58, 67.8, 6.4, 5.34, 2, 4.2};

    display<int>(a, 10);
    selection_sort<int>(a, 10);
    display<int>(a, 10);

    display<double>(b, 10);
    selection_sort<double>(b, 10);
    display<double>(b, 10);

    return 0;
}
