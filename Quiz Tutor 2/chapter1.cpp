#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // maintain heap from bottom up
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // maintain heap from top down
    void heapifyDown(int index) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    // build heap from array
    MinHeap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // insertion function
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // extract minimum element (root)
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return minVal;
    }

    // get current minimum
    int peek() const {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    // return current heap array
    vector<int> getHeap() const {
        return heap;
    }

    // heap sort ascending
    vector<int> heapSortAscending() {
        MinHeap tempHeap = *this;  // Clone
        vector<int> sorted;
        while (!tempHeap.heap.empty()) {
            sorted.push_back(tempHeap.extractMin());
        }
        return sorted;
    }

    // heap sort descending
    vector<int> heapSortDescending() {
        vector<int> sorted = heapSortAscending();
        reverse(sorted.begin(), sorted.end());
        return sorted;
    }

    // print heap elements
    void printHeap() const {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    // initial input array
    vector<int> input = {12, 3, 5, 7, 19, 1, 8, 15, 4, 11, 6, 9, 14};

    cout << "initial array: ";
    for (int val : input) cout << val << " ";
    cout << endl;

    // build min-heap
    MinHeap heap(input);

    cout << "Min-heap: ";
    heap.printHeap();

    // insert number 2
    heap.insert(2);
    cout << "Min-heap after insert number 2: ";
    heap.printHeap();

    // heap sort in descending order
    cout << "Heap Sort in decreasing order: ";
    vector<int> desc = heap.heapSortDescending();
    for (int val : desc) cout << val << " ";
    cout << endl;

    // heap sort in ascending order
    cout << "Heap Sort in increasing order: ";
    vector<int> asc = heap.heapSortAscending();
    for (int val : asc) cout << val << " ";
    cout << endl;

    // get smallest element
    cout << "Priority Queue 1 (smallest): " << heap.peek() << endl;

    // delete smallest
    heap.extractMin();
    cout << "Min-heap after the delete section: ";
    heap.printHeap();

    // get new smallest
    cout << "Priority Queue 2 (next smallest): " << heap.peek() << endl;

    return 0;
}
