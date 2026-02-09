#include <iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=nullptr;
    }

};

// Node* createNode(Node* head, int val){
//   Node* newNode= new Node(val);
//   newNode->next= NULL;
//   return newNode;
// }
Node* insertAtEnd(Node* head, int val){
     Node* newNode= new Node(val);
    if(head==nullptr){
       return newNode;
        
    }
    Node* temp= head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next= newNode;
    return head;
}


void displaylist(Node* head){
    Node* temp= head;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head= nullptr;
    head= insertAtEnd(head, 10);
    head= insertAtEnd(head, 20);
    head= insertAtEnd(head, 30);
    head= insertAtEnd(head, 40);
    head= insertAtEnd(head,50);
    displaylist(head);
    
}