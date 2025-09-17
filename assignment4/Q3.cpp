#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    int half = n / 2;
    stack<int> s;

    
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

    
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    
    for (int i = 0; i < half; i++) {
        s.push(q.front());
        q.pop();
    }

   
    while (!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleaveQueue(q);

    
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
