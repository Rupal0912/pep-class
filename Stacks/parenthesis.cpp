#include<iostream>
#include<stack>
using namespace std;
string check(string s){
    stack<char> st;
    char prev= '#';
    for(char i : s){
        if(i=='('){
            st.push('(');
            prev= '(';
        }
        else if(i>='a' || i<='z'){
            st.push('O');
            prev = 'O';
        }
        else if(i=='*' || i=='+' || i =='-' || i == '/'){
            if(prev == '#' || prev == '(' || prev == 'X'){
                return "Invalid";
            }
            st.push('X');
            prev == 'X';
        }
        else if(i==')'){
            bool hasoperator = false;
            if(st.empty()) return "Unbalanced";
            while(!st.empty() && st.top()!='('){
                if(st.top()=='X')
                hasoperator= true;
                st.pop();
            }
            if(st.empty()) return "Unbalanced";
            st.pop();
            if(!hasoperator){
                return "redundant";
            }
            st.push('O');
            prev= 'O';
        }
    }
    while (!st.empty())
    {
        if(st.top() =='(')
        return "Unbalanced";
        st.pop();
    }
    return "Valid";
    

}