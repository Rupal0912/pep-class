// program to find sum till nth node in a singular linked list in O(1) time complexity.
#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    int prefixSum;  // stores cumulative sum till this node
    
    Node(int val) {
        data = val;
        next = nullptr;
        prefixSum = 0;
    }
};

class LinkedList {
    private:
    Node* head;
     Node* tail;
    int nodeCount;
    
    public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }
    
    // Insert at end with O(1) prefix sum maintenance
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        nodeCount++;
        
        if (!head) {
            head = newNode;
            newNode->prefixSum = val;
            tail = newNode;
        }
        else {
            newNode->prefixSum = tail->prefixSum + val;  // maintain prefix sum
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // Get sum till nth node in O(1) time - O(n) to reach node, but O(1) to get sum
    int getSumTillNthNode(int n) {
        if (n <= 0 || n > nodeCount) {
            cout << "Invalid node number!" << endl;
            return -1;
        }
        
        Node* current = head;
        for (int i = 1; i < n; i++) {
            current = current->next;
        }
        return current->prefixSum;  // O(1) lookup
    }
    
    // Get total sum in O(1)
    int getTotalSum() {
        if (!tail) return 0;
        return tail->prefixSum;
    }
    
    // Display all nodes with their prefix sums
    void display() {
        Node* current = head;
        int pos = 1;
        cout << "Node | Data | Prefix Sum" << endl;
        cout << "-----|------|------------" << endl;
        while (current != nullptr) {
            cout << pos << "    | " << current->data << "    | " << current->prefixSum << endl;
            current = current->next;
            pos++;
        }
    }
};

int main() {
    LinkedList list;
    
    // Insert nodes
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    
    cout << "Linked List with Prefix Sums:" << endl;
    list.display();
    
    cout << "\nSum till nodes (O(1) lookup):" << endl;
    cout << "Sum till 1st node: " << list.getSumTillNthNode(1) << endl;
    cout << "Sum till 2nd node: " << list.getSumTillNthNode(2) << endl;
    cout << "Sum till 3rd node: " << list.getSumTillNthNode(3) << endl;
    cout << "Sum till 4th node: " << list.getSumTillNthNode(4) << endl;
    cout << "Sum till 5th node: " << list.getSumTillNthNode(5) << endl;
    cout << "\nTotal sum: " << list.getTotalSum() << endl;
    
    return 0;
}