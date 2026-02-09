// check palindrome in a singly linked list using only stack and one traversal
#include <iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int val){
        data=val;
        next=nullptr;
    }
};
bool isPalindrome(Node* head){
    stack<int> st;
    Node* temp = head;

    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=nullptr){
        if(temp->data == st.top()){
        return false;
    }
    st.pop();
    temp=temp->next;
    }
    
    return true;
}

int main(){
    Node* head= new Node(10);
     head->next= new Node(20);
    head->next->next= new Node(30);
    head->next->next->next= new Node(20);
    head->next->next->next->next= new Node(10);
    bool isPalindrome(head);
}