#include <iostream>
using namespace std;

/*
Purpose:
Store an input value into a signed int and return the stored value

Inputs:
-long long inputvalue: allows reading values beyond int range safely

Process:
Assign the value to a signed int variable 

Output:

*/

//Function under test
int storeInSignedInt(long long inputvalue){
    int stored = static_cast<int>(inputvalue);
    return stored;
}

void runPredefinedTests();
void runCustomTests();

int main(){
    int choice;
    cout<<"1. Run Predefined Tests"<<endl;
    cout<<"2. Run Custom Tests"<<endl;
    cout<<"Enter your choice: ";
    cin>>choice;
    if(choice == 1){
        runPredefinedTests();
    } else if(choice == 2){
        runCustomTests();
    } else {
        cout<<"Invalid choice!"<<endl;
    }
    return 0;
}
