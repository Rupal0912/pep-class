#include <iostream>
#include <vector>
using namespace std;
// user defined data type
class Node {
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    public:
   Node(int data1){
        data=data1;
        next=nullptr;
    }


};
// array-> linked list
Node* convertarraytoll(vector <int> arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp= new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
// length of linked list
int lenofll(Node* head){
    int count=0;
    Node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
        count++;

    }
    cout<<endl;
    return count;
}
// search for an element
int searchinll(Node* head, int val){
    Node* temp= head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;

    }
    return 0;
}
// displaying linked list
void print(Node* head){
    Node* temp= head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
// deletion of head
Node* removesHead(Node* head){
    if(head==NULL) return head;
    Node* temp= head;
    head= head->next;
    delete temp;
    return head;
}
// DELETION OF TAIL
Node* removestail(Node* head){
    Node* temp= head;
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    while(temp->next->next!=nullptr){
        temp= temp->next;
    }
    delete temp->next;
    temp->next= nullptr;
    return head;
}
// Deletion of kth element
Node* deletek(Node* head,int k){
    if(head==nullptr) return head;
    if(k==1){
        Node* temp= head;
        head= head->next;
        delete temp;
        return head;
    }
    int count=0;
    Node* temp=  head;
    Node* prev= nullptr;
    while(temp!=nullptr){
        count++;
        if(count==k){
            prev->next= prev->next->next;
            delete temp;
            break;
        }
        prev= temp;
        temp= temp->next;
    }
    return head;
}
// insert at head;
Node* insertathead(Node* head, int val){
    Node* temp= new Node(val, head);
    return temp;
}
Node* insertattail(Node* head, int val){
    if(head==nullptr) return new Node(val);
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    Node* newnode= new Node(val);
    temp->next= newnode;
    return head;
}
Node* insertatposition(Node* head, int el, int k){
    if(head==nullptr){
        if(k==1) return new Node(el);
        else return head;

    }
    if(k==1){
        return new Node(el, head);
    }
    int cnt=0;
    Node* temp= head;
    while(temp!=nullptr)
    {
        cnt++;
        if(cnt==(k-1)){
            Node* x= new Node(el);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr={23,5,8,7};
    Node* head= convertarraytoll(arr);
    // cout<< head->data;
    // Node* temp= head;
    // while(temp){
    //     cout<<temp->data<<" ";
    //     temp=temp->next;

    // }

    // cout<< "the linked list and its length: "<<lenofll(head);
    // cout<<endl;
    // cout<<"here is if element present or not: "<<searchinll(head, 80);
    head= insertatposition(head, 345, 3);
    print(head);
}