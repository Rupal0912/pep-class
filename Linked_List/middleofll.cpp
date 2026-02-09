// #include<iostream>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node(int data1){
//         data= data1;
//         next=nullptr;
//     }
// };
// Node* findMiddle(Node* head) {
//     if(head == NULL) return NULL;

//     Node* slow = head;
//     Node* fast = head;

//     while(fast != NULL && fast->next != NULL) {
//         slow = slow->next;        // 1 step
//         fast = fast->next->next;  // 2 steps
//     }

//     return slow;
// }
// int main(){
//      Node* head = new Node(1);
//     head->next = new Node(2);
//     head->next->next = new Node(3);
//     head->next->next->next = new Node(4);
//     head->next->next->next->next = new Node(5);

//     Node* mid = findMiddle(head);

//     if(mid != NULL)
//         cout << "Middle Element: " << mid->data;
//     else
//         cout << "List is empty";

//     return 0;
// }
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Print Linked List
void printList(Node* head) {
    if(head == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Insert at Head
void insertAtHead(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) { // empty list
        head = tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

// Insert at Tail
void insertAtTail(Node* &head, Node* &tail, int val) {
    Node* newNode = new Node(val);

    if(head == NULL) { // empty list
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

// Insert at Position (1-based index)
void insertAtPosition(Node* &head, Node* &tail, int pos, int val) {

    if(pos <= 1) {
        insertAtHead(head, tail, val);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(temp != NULL && count < pos - 1) {
        temp = temp->next;
        count++;
    }

    // If position beyond length → insert at tail
    if(temp == NULL || temp->next == NULL) {
        insertAtTail(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
}
 Node* findMiddle(Node* head) {
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;        // 1 step
        fast = fast->next->next;  // 2 steps
    }

    return slow;
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;

    int choice;

    while(true) {
        cout << "\n1.Insert Head  2.Insert Tail  3.Insert Position  4.Print  5.Exit\n";
        cin >> choice;

        if(choice == 1) {
            int val;
            cout << "Value: ";
            cin >> val;
            insertAtHead(head, tail, val);
        }
        else if(choice == 2) {
            int val;
            cout << "Value: ";
            cin >> val;
            insertAtTail(head, tail, val);
        }
        else if(choice == 3) {
            int val, pos;
            cout << "Position & Value: ";
            cin >> pos >> val;
            insertAtPosition(head, tail, pos, val);
        }
        else if(choice == 4) {
            printList(head);
        }
        else if(choice == 5) {
            break;
        }
        else {
            cout << "Invalid Choice\n";
        }
    }
    Node* mid = findMiddle(head);

    if(mid != NULL)
        cout << "Middle Element: " << mid->data;
    else
        cout << "List is empty";


    return 0;
}
