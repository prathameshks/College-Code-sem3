#include <iostream>
using namespace std;

// defining minimun function utility function
//<return_type> <name>(<params>){return (<condition>) ? <if true value>:<if false value>;}
int min(int a, int b) { return (a > b) ? b : a; }

int fibo_search(int arr[], int key, int n) {
    // last fibo series elements
    int fibom2 = 0;
    int fibom1 = 1;
    int fibom = 1;

    // finding fibo elmt >= n
    while (arr[n - 1] > fibom) {
        fibom2 = fibom1;
        fibom1 = fibom;
        fibom = fibom1 + fibom2;
    }

    // setting i and offset
    int i, offset = -1;

    // while fibom is > 0
    while (fibom > 0) {
        i = min(offset + fibom2, n - 1);
        // if key is greater then move array 1 below and offset is i
        if (arr[i] < key) {
            fibom = fibom1;
            fibom1 = fibom2;
            fibom2 = fibom - fibom1;
            offset = i;
        } else if (arr[i] > key) {
            // if key is less then move 2 and same offset
            fibom = fibom2;
            fibom1 -= fibom;
            fibom2 = fibom - fibom1;
        } else {
            // else found
            return i;
        }
    }
    // not found
    return -1;
}

int main() {
    int arr[] = {1, 2, 4, 6, 7, 9, 10, 13, 15, 17, 19, 22};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << fibo_search(arr, 22, n);
    return 0;
}