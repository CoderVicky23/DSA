#include <iostream>
using namespace std;

void bubbleSort(int * arr, int n) {
    bool k;
    for (int j=0; j<n; j++) {
        k = 0;
        for (int i=0; i<n-j-1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
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
    int arr[] = {0, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    bubbleSort(arr, n);
    print(arr, n);
    return 0;
}