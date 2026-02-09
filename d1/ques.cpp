// Write a program with one user defined fucn and one main func .The user defined fucn takes one integer, modify the value return back the value
// ques.cpp
#include <iostream>
using namespace std;

int newval(int num){
    num = num + 3;
    return num;
}

int main(){
    int num;
    cout << "Enter the number: ";
    cin >> num;

    cout << "Before modification: " << num << endl;
    num = newval(num);
    cout << "After modification: " << num << endl;

    return 0;
}
