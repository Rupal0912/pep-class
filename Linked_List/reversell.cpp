#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data= val;
        next=nullptr;
    }
};
Node* reverse(Node* head){
    Node* prev= nullptr;
    Node* curr= head;
    Node* next=nullptr;
    while(curr!=nullptr){
        next=curr->next;
        curr->next= prev;
        prev=curr;
        curr=next;
    }
    return prev;
}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
int main(){
    Node* head= new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(30);
    head->next->next->next= new Node(40);
    head->next->next->next->next= new Node(50);
      cout << "Original: ";
    print(head);
    head = reverse(head);
    cout<<"\n reversed:";
    print(head);
 
}