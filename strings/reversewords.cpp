#include<iostream>
#include<string>
using namespace std;
void revrange(string &s, int start, int end){
    while(start<end){
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
void revword(string &s){
    int start=0;
    int n= s.size();
    for(int i=0;i<n;i++){
        if(s[i]==' '){
            revrange(s, start, i-1);
            start= i+1;
        }
    }
    revrange(s,start, n-1);
}
int main(){
    string s="hello world";
    revword(s);
    cout<<s;

}