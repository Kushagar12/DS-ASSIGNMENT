#include <iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        size = 0;
    }

    
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    
    void insert(int x) {
        arr[size] = x;
        int i = size;
        size++;

        
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    
    int getMax() {
        if (size == 0)
            return -1; 
        return arr[0];
    }

    
    void heapify(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && arr[l] > arr[largest])
            largest = l;

        if (r < size && arr[r] > arr[largest])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    
    int extractMax() {
        if (size <= 0)
            return -1;
        if (size == 1) {
            size--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[size - 1];
        size--;

        heapify(0);

        return root;
    }

    
    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(40);
    pq.insert(30);
    pq.insert(5);
    pq.insert(50);

    cout << "Max element: " << pq.getMax() << endl;

    cout << "Extracting elements: ";
    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }
    cout << endl;

    return 0;
}
