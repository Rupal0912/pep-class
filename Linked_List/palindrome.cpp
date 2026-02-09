#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data= val;
        next=nullptr;
    }
};
Node* middle(Node* head){
    Node* fast= head;
    Node* slow= head;
    while(fast!=NULL && fast->next!=NULL){
        slow= slow->next;
        fast= fast->next->next;
    }
    return slow;
}
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
bool palindrome(Node* head){
       if(head== nullptr || head->next== nullptr){
        return true;
       }
       Node* mid= middle(head);
       Node* secondhalf= reverse(mid->next);
       Node* firsthalf= head;
       while(secondhalf !=nullptr){
        if(firsthalf->data !=secondhalf->data){
            return false;
        }
             firsthalf = firsthalf->next;
        secondhalf = secondhalf->next;
        
        
       }
       return true;

}

int main(){
    Node* head= new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(30);
    head->next->next->next= new Node(20);
    head->next->next->next->next= new Node(10);
    if(palindrome(head)) {
    cout << "Palindrome" << endl;
} else {
    cout << "Not a Palindrome" << endl;
}
}