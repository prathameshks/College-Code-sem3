#include <iostream>
using namespace std;

void insertionsort(int arr[], int n) {
    int i, key, j;
    for (i = 0; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }
    for (int k = 0; k < 10; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}

int main() {
    int a[10] = {1, 45, 2, 5, 2, 5, 6, 87, 4, 2};
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    insertionsort(a, 10);
    for (int i = 0; i < 10; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}