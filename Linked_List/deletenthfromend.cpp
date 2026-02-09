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
// Node* deletenthnode(Node* head, int n){
//     if(head == NULL) return head;

//     Node* fast = head;
//     Node* slow = head;

//     for(int i = 0; i < n; i++){
//         if(fast == NULL) return head; 
//         fast = fast->next;
//     }

//     if(fast == NULL){ // delete first node
//         Node* temp = head;
//         head = head->next;
//         delete temp;
//         return head;
//     }

//     while(fast->next != NULL){
//         slow = slow->next;
//         fast = fast->next;
//     }

//     Node* del = slow->next;
//     slow->next = del->next;
//     delete del;

//     return head;
// }

Node* deletenthnode(Node* head, int n){
    if(head == NULL) return head;
    if(n==1){
        Node* temp= head;
        head= head->next;
        delete temp;
        return head;
    }
    Node* fast= head;
    Node* slow= head;
    for(int i=0;i<n;i++){
            if(fast == NULL) return head; 
        fast=fast->next;
    }

    while(fast->next!=NULL){
        slow=  slow->next;
        fast= fast->next;
    }
    Node* del= slow->next;
    slow->next=del->next;
    delete del;
    return head;
}
void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp= temp->next;
    }
}
int main(){
    Node* head = new Node(10);
     head->next= new Node(20);
    head->next->next= new Node(30);
    head->next->next->next= new Node(40);
    head->next->next->next->next= new Node(50);
    print(head);
   head = deletenthnode(head, 3);

    cout<<"after deletion: ";
    
    print(head);
}