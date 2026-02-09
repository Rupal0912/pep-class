
#include<iostream>
#include<string>
using namespace std;

//Function under test
int storeInSignedInt(long long inputvalue);

//core test runner(Resuable)
void runTest(const string& testid, long long input, int expected){
    int actual = storeInSignedInt(input);
    cout<<"["<<testid<<"] ";
    cout<<"Input: "<<input<<"\n";
    cout<<"Expected: "<<expected<<"\n";
    cout<<"Actual: "<<actual<<"\n";
    if(actual == expected){
        cout<<"Result: PASS\n\n";
    } else {    
        cout<<"Result: FAIL\n\n"; 
    }
}

void runPredefinedTests(){
    //Predefined test cases
    runTest("TC01", 0, 0); //Normal case
    runTest("TC02", 100, 100); //Negative value
    runTest("TC03", 2147483647LL, 2147483647); //Max int
    runTest("TC04", -2147483648LL, -2147483648); //Min int
    runTest("TC05", 2147483648LL, -2147483648); //Overflow case
    runTest("TC06", -2147483649LL, 2147483647); //Underflow case
    runTest("TC07", -2147483649LL, 2147483647); //Large overflow
    runTest("TC08", 4924967296LL, 0); //Max long long
    runTest("TC09", -4924967296LL, 0); //Min long long
    runTest("TC10", 99999999999LL, storeInSignedInt(99999999999LL)); //Random large number
}
void runCustomTests(){
    int t;
    cout<<"Enter number of custom tests: ";
    cin>>t;
    for(int i=1;i<=t;i++){
        long long input;
        int expected;
        cout<<" Test Case "<<i<<":\n";
        cout<<" Enter input value : ";
        cin>>input;
        cout<<" Enter expected value : ";
        cin>>expected;
        runTest("Custom_TC" + to_string(i), input, expected);
    }
}