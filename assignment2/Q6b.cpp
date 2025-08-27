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
    int rows, cols;
    int n1, n2;

    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> n1;
    int row1[n1], col1[n1], val1[n1];

    cout << "Enter non-zero elements of first matrix (row, column, value):" << endl;
    for (int i = 0; i < n1; i++) {
        cin >> row1[i] >> col1[i] >> val1[i];
    }

    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> n2;
    int row2[n2], col2[n2], val2[n2];

    cout << "Enter non-zero elements of second matrix (row, column, value):" << endl;
    for (int i = 0; i < n2; i++) {
        cin >> row2[i] >> col2[i] >> val2[i];
    }

    
    sortTriplets(row1, col1, val1, n1);
    sortTriplets(row2, col2, val2, n2);

    
    int rowR[n1 + n2], colR[n1 + n2], valR[n1 + n2];
    int i = 0, j = 0, k = 0;

    
    while (i < n1 && j < n2) {
        if (row1[i] < row2[j] || (row1[i] == row2[j] && col1[i] < col2[j])) {
            rowR[k] = row1[i];
            colR[k] = col1[i];
            valR[k] = val1[i];
            i++; k++;
        } else if (row2[j] < row1[i] || (row2[j] == row1[i] && col2[j] < col1[i])) {
            rowR[k] = row2[j];
            colR[k] = col2[j];
            valR[k] = val2[j];
            j++; k++;
        } else {
           
            int summedVal = val1[i] + val2[j];
            if (summedVal != 0) {
                rowR[k] = row1[i];
                colR[k] = col1[i];
                valR[k] = summedVal;
                k++;
            }
            i++; j++;
        }
    }

    
    while (i < n1) {
        rowR[k] = row1[i];
        colR[k] = col1[i];
        valR[k] = val1[i];
        i++; k++;
    }

    
    while (j < n2) {
        rowR[k] = row2[j];
        colR[k] = col2[j];
        valR[k] = val2[j];
        j++; k++;
    }

    cout << "\nResultant sparse matrix after addition (row, column, value):" << endl;
    for (int idx = 0; idx < k; idx++) {
        cout << rowR[idx] << " " << colR[idx] << " " << valR[idx] << endl;
    }

    return 0;
}
