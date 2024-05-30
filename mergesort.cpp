#include <iostream>
#include <vector>
using namespace std;

void merge(int * arr, int low, int mid, int high) {
    vector <int> temp;
    int l = low;
    int r = mid+1;
    while (l <= mid && r <= high) {
        if (arr[l] <= arr[r]) {
            temp.push_back(arr[l]);
            l++;
        }
        else {
            temp.push_back(arr[r]);
            r++;
        }
    }
    while (l <= mid) {
        temp.push_back(arr[l]);
        l++;
    }
    while (r <= high) {
        temp.push_back(arr[r]);
        r++;
    }
    for (int i=low, j=0; i<=high; i++, j++) {
        arr[i] = temp[j];
    }
}

void mergeSort(int * arr, int low, int high) {
    if (low >= high) return;
    int mid = (high + low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void print(int * arr, int n) {
    for (int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    int arr[] = {3, 2, 4, 1, 3};
    int n = sizeof(arr)/sizeof(int);
    mergeSort(arr, 0, n-1);
    print(arr, n);
    return 0;
}