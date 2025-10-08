#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        q1.push(x);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }
        
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        
        q1.pop();

        
        swap(q1, q2);
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int res = q1.front();

        
        q2.push(res);
        q1.pop();

        
        swap(q1, q2);

        return res;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    StackUsingTwoQueues s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << "\n"; 
    s.pop();
    cout << s.top() << "\n";  
    s.pop();
    s.push(40);
    cout << s.top() << "\n";  
    s.pop();
    cout << s.top() << "\n";  

    return 0;
}
