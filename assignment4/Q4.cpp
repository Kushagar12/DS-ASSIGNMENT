#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<char> q;
    int count[26] = {0}; 

    char ch;
    while (cin >> ch) {
        q.push(ch); 
        count[ch - 'a']++; 

        
        while (!q.empty() && count[q.front() - 'a'] > 1) {
            q.pop();
        }

        
        if (!q.empty()) {
            cout << q.front() << " ";
        } else {
            cout << "-1 ";
        }
    }

    return 0;
}
