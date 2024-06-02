#include <iostream>
using namespace std;

void insertionSort(int * arr, int n) {
    for (int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void print(int * arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 4, 1, 9, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    insertionSort(arr, n);
    print(arr, n);
    return 0;
}