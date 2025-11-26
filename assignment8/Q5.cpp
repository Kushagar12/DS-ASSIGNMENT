#include <iostream>
using namespace std;


void heapifyMax(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapifyMax(arr, n, largest);
    }
}


void heapifyMin(int arr[], int n, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}


void heapSortIncreasing(int arr[], int n) {
    
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMax(arr, n, i);

    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMax(arr, i, 0);
    }
}


void heapSortDecreasing(int arr[], int n) {
    
    for (int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapifyMin(arr, i, 0);
    }
}

int main() {
    int arr[] = {10, 3, 5, 2, 8, 15};
    int n = sizeof(arr) / sizeof(arr[0]);

    
    int inc[100];
    for(int i = 0; i < n; i++) inc[i] = arr[i];

    heapSortIncreasing(inc, n);
    cout << "Sorted Increasing: ";
    for (int i = 0; i < n; i++) cout << inc[i] << " ";
    cout << endl;

    
    int dec[100];
    for(int i = 0; i < n; i++) dec[i] = arr[i];

    heapSortDecreasing(dec, n);
    cout << "Sorted Decreasing: ";
    for (int i = 0; i < n; i++) cout << dec[i] << " ";
    cout << endl;

    return 0;
}
