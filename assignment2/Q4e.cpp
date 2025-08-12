#include <iostream>
using namespace std;

int main() {
    char ch;

    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (ch >= 'A' && ch <= 'Z') {
        // Convert to lowercase by adding difference between 'a' and 'A'
        char lower = ch + ('a' - 'A');
        cout << "Lowercase character: " << lower << endl;
    } else {
        cout << "Input is not an uppercase letter." << endl;
    }

    return 0;
}
