#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the length of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = 0;

    for(int i = 0; i < n; i++) {
        bool isDistinct = true;

        
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if(isDistinct) {
            distinctCount++;
        }
    }

    cout << "Number of distinct elements: " << distinctCount << endl;

    return 0;
}



