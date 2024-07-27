#include <iostream>
using namespace std;

void print(int * arr, int n)  {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void quickSort(int * arr, int low, int high) {
    int pivot = low;
    int i = low+1, j = high;
    while (i <= j) {
        while (arr[i] < arr[pivot]) {
            i++;
        }
        while (arr[j] > arr[pivot]) {
            j--;
        }
        if (i >= j) break;
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    int mid = j;
    swap(arr[pivot], arr[mid]);
    if (mid-1 > low) quickSort(arr, low, mid-1);
    if (mid+1 < high) quickSort(arr, mid+1, high);
}

int main() {
    int arr[] = {1};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr, 0, n-1);
    print(arr, n);
    return 0;
}