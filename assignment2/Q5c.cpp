#include<iostream>
using namespace std;
int main(){
    int r, c;
    cout << "Enter rows: ";
    cin >> r;
    cout << "Enter cols: ";
    cin >> c;

  
    int n = r; 
    int s = (n * (n + 1)) / 2;
    int arr[s];

    cout << "Enter " << s << " elements (lower triangular matrix elements row-wise): " << endl;
    for (int i = 0; i < s; i++) {
        cin >> arr[i];
    }

    int k = 0;
    cout << "Resultant matrix is: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {
                cout << arr[k] << " ";
                k++;
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}
