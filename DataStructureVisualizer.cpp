// 📌 Data Structure Visualizer in C++
// Supports Stack, Queue, Linked List using menu-driven program

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// ------------------ Linked List ------------------
struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void insertAtEnd(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteFromFront() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// ------------------ Main Program ------------------
int main() {
    stack<int> s;
    queue<int> q;
    LinkedList ll;

    int choice, val;

    while (true) {
        cout << "\n===== Data Structure Visualizer =====\n";
        cout << "1. Stack\n2. Queue\n3. Linked List\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\n-- Stack Operations --\n1. Push\n2. Pop\n3. Display\nEnter option: ";
                cin >> val;
                if (val == 1) {
                    cout << "Enter value to push: ";
                    cin >> val;
                    s.push(val);
                } else if (val == 2) {
                    if (!s.empty()) {
                        cout << "Popped: " << s.top() << endl;
                        s.pop();
                    } else cout << "Stack is empty.\n";
                } else {
                    stack<int> temp = s;
                    cout << "Stack (Top to Bottom): ";
                    while (!temp.empty()) {
                        cout << temp.top() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 2:
                cout << "\n-- Queue Operations --\n1. Enqueue\n2. Dequeue\n3. Display\nEnter option: ";
                cin >> val;
                if (val == 1) {
                    cout << "Enter value to enqueue: ";
                    cin >> val;
                    q.push(val);
                } else if (val == 2) {
                    if (!q.empty()) {
                        cout << "Dequeued: " << q.front() << endl;
                        q.pop();
                    } else cout << "Queue is empty.\n";
                } else {
                    queue<int> temp = q;
                    cout << "Queue (Front to Rear): ";
                    while (!temp.empty()) {
                        cout << temp.front() << " ";
                        temp.pop();
                    }
                    cout << endl;
                }
                break;

            case 3:
                cout << "\n-- Linked List Operations --\n1. Insert at end\n2. Delete from front\n3. Display\nEnter option: ";
                cin >> val;
                if (val == 1) {
                    cout << "Enter value to insert: ";
                    cin >> val;
                    ll.insertAtEnd(val);
                } else if (val == 2) {
                    ll.deleteFromFront();
                } else {
                    ll.display();
                }
                break;

            case 4:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
