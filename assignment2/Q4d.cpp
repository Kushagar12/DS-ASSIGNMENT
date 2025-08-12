#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // Clear newline character from input buffer

    string arr[n];

    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    // Sort the array of strings
    sort(arr, arr + n);

    cout << "\nStrings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
