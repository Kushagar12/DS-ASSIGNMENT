#include <iostream>
using namespace std;


void swapInt(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


void sortTriplets(int row[], int col[], int val[], int n) {
    for (int i = 0; i < n -1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (row[j] > row[j+1] || (row[j] == row[j+1] && col[j] > col[j+1])) {
                swapInt(row[j], row[j+1]);
                swapInt(col[j], col[j+1]);
                swapInt(val[j], val[j+1]);
            }
        }
    }
}

int main() {
    int rows, cols, nonZero;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> nonZero;

    int row[nonZero], col[nonZero], val[nonZero];
    int tRow[nonZero], tCol[nonZero], tVal[nonZero];

    cout << "Enter non-zero elements as row, column, value:" << endl;
    for (int i = 0; i < nonZero; i++) {
        cin >> row[i] >> col[i] >> val[i];
    }

    
    for (int i = 0; i < nonZero; i++) {
        tRow[i] = col[i];
        tCol[i] = row[i];
        tVal[i] = val[i];
    }


    sortTriplets(tRow, tCol, tVal, nonZero);

    cout << "\nTransposed sparse matrix (row, column, value):" << endl;
    for (int i = 0; i < nonZero; i++) {
        cout << tRow[i] << " " << tCol[i] << " " << tVal[i] << endl;
    }

    return 0;
}
