class node{
    public:
    int data;
    node* next;

};
1. head = NULL;
2. -1create newNode:
   Node* newNode= new Node(val);
   newNode->next= NULL;
3. insertatend(head, value);
4. 1.list empty(head==NULL)
   head== newNode();
   2.List not emppty:
   go to last node: (temp->next==null)
   temp->next= newnode;
5. printlist(head);


// naming conventions: 1. ALL the variable names   func names
// will be in camel-case
// 2.all class names, threads names, exception names , error names, class component
// .or in general components must be in pascal case
// 3.all const values should be taken in block letters.
// 4.K R notation