#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int left = 0, right = n - 1;
    int start = arr[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Expected value at mid
        int expected = start + mid;

        if (arr[mid] == expected) {
            // Missing number is on the right
            left = mid + 1;
        } else {
            // Missing number is on the left
            right = mid - 1;
        }
    }

    // Missing number is at position 'left'
    return start + left;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8};  // 5 is missing
    int n = sizeof(arr) / sizeof(arr[0]);

    int missing = findMissing(arr, n);
    cout << "Missing number is: " << missing << endl;

    return 0;
}
