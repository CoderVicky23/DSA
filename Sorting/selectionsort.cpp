#include <iostream>
using namespace std;

void selectionSort(int * arr, int n) {
    for (int i=0; i<n; i++) {
        bool k = 0;
        for (int j=0; j<n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                k = 1;
            }
        }
        if (!k) break;
    }
}

void print(int * arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {9, 4, 3, 7, 1, 0};
    int n = sizeof(arr)/sizeof(int);
    selectionSort(arr, n);
    print(arr, n);
    return 0;
}