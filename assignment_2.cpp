#include <iostream>
using namespace std;

class Node {
    private:
    int iData;
    
    public:
    Node(int key) {
        iData = key;
    }
    
    int getKey() {
        return iData;
    }
    
    void setKey(int id) {
        iData = id;
    }
};

class Heap {
    private:
    Node** heapArray;
    int maxSize;
    int currentSize;
    
    public:
    Heap(int mx) {
        maxSize = mx;
        currentSize = 0;
        heapArray = new Node*[maxSize + 1];
    }
    
    bool isEmpty() {
        return currentSize == 0;
    }
    
    bool isFull() {
        return currentSize == maxSize;
    }
    
    bool hasLeftChild(int index) {
        return 2 * index >= currentSize;
    }
    
    bool hasRightChild(int index) {
        return 2 * index + 1 >= currentSize;
    }
    
    bool insert(int key) {
        if (isFull()) {
            return false;
        }
        Node * newNode = new Node(key);
        heapArray[++currentSize] = newNode;
        trickleUp(currentSize);
        return true;
    }
    
    void trickleUp(int index) {
        int parent = index / 2;
        Node* bottom = heapArray[index];
        
        while (index > 1 && heapArray[parent]->getKey() < bottom->getKey()) {
            heapArray[index] = heapArray[parent];
            index = parent;
            parent = parent / 2;
        }
        heapArray[index] = bottom;
    }
    
    void displayHeap() {
        for (int i = 1; i <= currentSize; ++i) {
            cout << heapArray[i]->getKey() << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {12, 3, 5, 7, 19, 1, 8, 15, 4, 11, 6, 9, 14};
    cout << "Array sebelum max heap: ";
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        cout << arr[i] << " ";
    }
    
    cout << endl;
    
    Heap heap(10);
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        heap.insert(arr[i]);
    }
    
    cout << endl;
    
    cout << "Min Heap: ";
    heap.displayHeap();
    cout << endl;
    
    return 0;
}
