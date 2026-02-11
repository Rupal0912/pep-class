#include<iostream>
#include<stack>
using namespace std;

void inserttemp(stack<int> &st, int temp){
    if(st.empty()|| st.top() <= temp){
        st.push(temp);
        return;
    }
    int x = st.top();
    st.pop();
    inserttemp(st,temp);
    st.push(x);
}
void sort(stack<int> &st){
    if(st.empty()) return;
    int temp= st.top();
    st.pop();
    sort(st);
    inserttemp(st,temp);
}
int main(){

     stack<int> st;

    // pushing elements
    st.push(2);
    st.push(4);
     st.push(1);
      st.push(3);
    // sort the stack
    sort(st);

    // print sorted stack
    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}