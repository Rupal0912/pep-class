
// #include <cassert>
// #include <iostream>
// using namespace std;

// int newval(int num);
// void runtest(int actual, int expected){
//     int n= newval(actual);
//     if(n==expected){
//         cout<<"Test passed: modify "<<actual<<" to "<<n<<endl;
//     }
//     else{
//         cout<<"Test failed: modify "<<actual<<" to "<<n<<", expected "<<expected<<endl;
// }
// }
// void predefinedTests(){
//     runtest(5, 8);
//     runtest(0, 3);
//     runtest(-2, 1);
// }
// void runtest(int actual, int expected){

// }

// int main() {
//     assert(newval(5) == 8);
//     assert(newval(0) == 3);
//     assert(newval(-2) == 1);

//     cout << "All tests passed ✅\n";
//     return 0;
// }
// questest.cpp
#include <cassert>
#include <iostream>
using namespace std;

// function declaration (must match ques.cpp)
int newval(int num);

void runTest(int input, int expected){
    int result = newval(input);
    assert(result == expected);
    cout << "Test passed: " << input << " → " << result << endl;
}

int main(){
    runTest(5, 8);
    runTest(0, 3);
    runTest(-2, 1);

    cout << "All tests passed ✅" << endl;
    return 0;
}
