#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;


bool isEmpty() {
    return front == -1;
}


bool isFull() {
    return rear == MAX - 1;
}


void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full! Cannot enqueue.\n";
        return;
    }
    if (isEmpty()) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
    cout << "Enqueued: " << item << endl;
}


int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty! Cannot dequeue.\n";
        return -1;  
    }
    int item = queue[front];
    if (front == rear) {
        
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    cout << "Dequeued: " << item << endl;
    return item;
}


int peek() {
    if (isEmpty()) {
        cout << "Queue is empty! Nothing to peek.\n";
        return -1;
    }
    return queue[front];
}


void display() {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

int main() {
    int choice, item;

    while (true) {
        cout << "\nQueue Operations Menu\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Check if Queue is Empty\n";
        cout << "4. Check if Queue is Full\n";
        cout << "5. Display Queue\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to enqueue: ";
                cin >> item;
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                if (isEmpty())
                    cout << "Queue is empty.\n";
                else
                    cout << "Queue is not empty.\n";
                break;
            case 4:
                if (isFull())
                    cout << "Queue is full.\n";
                else
                    cout << "Queue is not full.\n";
                break;
            case 5:
                display();
                break;
            case 6:
                item = peek();
                if (item != -1)
                    cout << "Front element is: " << item << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
