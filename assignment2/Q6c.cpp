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


int findValue(int row[], int col[], int val[], int n, int r, int c) {
    for (int i = 0; i < n; i++) {
        if (row[i] == r && col[i] == c)
            return val[i];
    }
    return 0;
}

int main() {
    int m1, n1, m2, n2;
    cout << "Enter number of rows and columns of first matrix: ";
    cin >> m1 >> n1;

    cout << "Enter number of non-zero elements in first matrix: ";
    int nz1;
    cin >> nz1;

    int row1[nz1], col1[nz1], val1[nz1];
    cout << "Enter non-zero elements of first matrix (row, column, value):" << endl;
    for (int i = 0; i < nz1; i++) {
        cin >> row1[i] >> col1[i] >> val1[i];
    }

    cout << "Enter number of rows and columns of second matrix: ";
    cin >> m2 >> n2;

    if (n1 != m2) {
        cout << "Matrix multiplication not possible. Number of columns of first matrix must equal number of rows of second matrix." << endl;
        return 0;
    }

    cout << "Enter number of non-zero elements in second matrix: ";
    int nz2;
    cin >> nz2;

    int row2[nz2], col2[nz2], val2[nz2];
    cout << "Enter non-zero elements of second matrix (row, column, value):" << endl;
    for (int i = 0; i < nz2; i++) {
        cin >> row2[i] >> col2[i] >> val2[i];
    }

    
    sortTriplets(row1, col1, val1, nz1);
    sortTriplets(row2, col2, val2, nz2);


    int rowR[m1 * n2], colR[m1 * n2], valR[m1 * n2];
    int k = 0;

    
    for (int i = 0; i < m1; i++) {         
        for (int j = 0; j < n2; j++) {      
            int sum = 0;
            
            for (int x = 0; x < n1; x++) {
                int valA = findValue(row1, col1, val1, nz1, i, x);
                int valB = findValue(row2, col2, val2, nz2, x, j);
                sum += valA * valB;
            }
            if (sum != 0) {
                rowR[k] = i;
                colR[k] = j;
                valR[k] = sum;
                k++;
            }
        }
    }

    cout << "\nResultant sparse matrix after multiplication (row, column, value):" << endl;
    for (int idx = 0; idx < k; idx++) {
        cout << rowR[idx] << " " << colR[idx] << " " << valR[idx] << endl;
    }

    return 0;
}

