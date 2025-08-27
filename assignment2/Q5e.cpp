#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the symmetric matrix (n x n): ";
    cin >> n;

    int size = (n * (n + 1)) / 2;
    int arr[size];

    cout << "Enter " << size << " elements of upper triangular matrix row-wise (including diagonal): " << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k = 0;
    cout << "Resultant symmetric matrix is: " << endl;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) {
                
                cout << arr[k] << " ";
                k++;
            } else {
                
                int index = (j * n) - (j * (j + 1) / 2) + (i - j);
                cout << arr[index] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
