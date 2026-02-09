#include<iostream>
#include<cassert>
using namespace std;

void modifybyreference(int &input);
void tests(){
    int a=10;
    modifybyreference(a);
    assert(a==20);
    cout<<"Test passed: modified value is "<<a<<endl;
}

void modifybyreference(int &input){
    input = input * 2;
}

int main(){
    tests();
    cout<<"All tests passed!"<<endl;
    return 0;
}