#include <bits/stdc++.h>
using namespace std;

class minHeap {
    vector<int> heap;

    int parent (int i) { return (i - 1) / 2; }
    int left (int i) { return 2 * i + 1; }
    int right (int i) { return 2 * i + 2; }

    void bubbleUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        int smallest = i;
        int l = left(i), r = right(i);
        if (l < heap.size() && heap[l] < heap[smallest]) smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest]) smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    public:
    void insert(int val) {
        heap.push_back(val);
        bubbleUp(heap.size()-1);
    }

    int extractMin() {
        if (heap.empty()) return -1;
        int top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapify(0);
        return top;
    }

    int getMin() {
        return (heap.empty() ? -1 : heap[0]);
    }

    void printHeap() {
        for (int i: heap) cout << i << "  ";
        cout << endl;
    }

    void buildHeap(vector<int>& arr) {
        heap = arr;
        for (int i=heap.size()/2 - 1; i>=0; i--) heapify(i);
    }

};

int main() {
    vector<int> arr = {4, 8, 2, 1, 5, 9, 1, 7, 6};
    minHeap mini;
    mini.buildHeap(arr);
    mini.printHeap();
    // for (int i=0; i<arr.size(); i++) {
    //     mini.insert(arr[i]);
    // }
    // mini.printHeap();   
    return 0;
}