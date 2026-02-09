
#include <iostream>
using namespace std;
int modifybyreference(int &input){
    input = input +10;
    cout<<"inside func, modified value:"<<input<<endl;

}
int main(){
    int val=5;
    cout<<"before func call, value:"<<val<<endl;
    modifybyreference(val);
    cout<<"after func call, value:"<<val<<endl;
    return 0;
    
}