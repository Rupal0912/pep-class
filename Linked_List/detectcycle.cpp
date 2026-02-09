#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data= val;
        next= nullptr;
    }
};
int cycledetection(Node* head){
    if(head==nullptr) return 0;
    Node*  fast= head;
    Node* slow= head;
    // Node* temp= head;
    while(fast!= nullptr && fast->next!=nullptr){
          slow = slow->next;
    fast = fast->next->next;
        if(fast==slow){
            int len=1;
            Node* temp= slow->next;
            while(temp!=slow){
                len++;
                temp= temp->next;
            }
            return len;
        }
    }
   
}
int main(){
   Node* head= new Node(10);
    head->next= new Node(20);
    head->next->next= new Node(30);
    head->next->next->next= new Node(40);
  head->next->next->next->next = head->next;
    int length=cycledetection(head);
}
