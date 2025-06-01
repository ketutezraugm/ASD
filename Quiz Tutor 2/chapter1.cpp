#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Maintain heap from bottom up
    void heapifyUp(int index) {
        int parent = (index - 1) / 2;
        while (index > 0 && heap[parent] > heap[index]) {
            swap(heap[parent], heap[index]);
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    // Maintain heap from top down
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
    // Constructor: Build heap from array
    MinHeap(vector<int> arr) {
        heap = arr;
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    }

    // Insertion function
    void insert(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    // Extract minimum element (root)
    int extractMin() {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
        return minVal;
    }

    // Get current minimum
    int peek() const {
        if (heap.empty()) throw runtime_error("Heap is empty!");
        return heap[0];
    }

    // Return current heap array
    vector<int> getHeap() const {
        return heap;
    }

    // Heap sort ascending
    vector<int> heapSortAscending() {
        MinHeap tempHeap = *this;  // Clone
        vector<int> sorted;
        while (!tempHeap.heap.empty()) {
            sorted.push_back(tempHeap.extractMin());
        }
        return sorted;
    }

    // Heap sort descending
    vector<int> heapSortDescending() {
        vector<int> sorted = heapSortAscending();
        reverse(sorted.begin(), sorted.end());
        return sorted;
    }

    // Print heap elements
    void printHeap() const {
        for (int val : heap) cout << val << " ";
        cout << endl;
    }
};

int main() {
    // Initial input array
    vector<int> input = {12, 3, 5, 7, 19, 1, 8, 15, 4, 11, 6, 9, 14};

    cout << "initial array: ";
    for (int val : input) cout << val << " ";
    cout << endl;

    // Build min-heap
    MinHeap heap(input);

    cout << "Min-heap: ";
    heap.printHeap();

    // Insert number 2
    heap.insert(2);
    cout << "Min-heap after insert number 2: ";
    heap.printHeap();

    // Heap sort in descending order
    cout << "Heap Sort in decreasing order: ";
    vector<int> desc = heap.heapSortDescending();
    for (int val : desc) cout << val << " ";
    cout << endl;

    // Heap sort in ascending order
    cout << "Heap Sort in increasing order: ";
    vector<int> asc = heap.heapSortAscending();
    for (int val : asc) cout << val << " ";
    cout << endl;

    // Get smallest element (priority queue)
    cout << "Priority Queue 1 (smallest): " << heap.peek() << endl;

    // Delete smallest
    heap.extractMin();
    cout << "Min-heap after the delete section: ";
    heap.printHeap();

    // Get new smallest
    cout << "Priority Queue 2 (next smallest): " << heap.peek() << endl;

    return 0;
}
