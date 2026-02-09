// given an integer input, store it in a signed int variable and print the value. observe what happens when the input exceeds the valid range of int.
#include <iostream>
#include <limits>
using namespace std;



int main() {
    long long n; 
     cout << "Input value: ";  
    cin >> n;
   

     
    int x = n;     
    cout << x << endl;

    return 0;
}
