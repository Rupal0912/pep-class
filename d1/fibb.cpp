#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, n;

    cout << "Enter first two Fibonacci numbers: ";
    cin >> a >> b;

    cout << "Enter range (1-100): ";
    cin >> n;

    if (n < 1 || n > 100) {
        cout << "Invalid range!";
        return 0;
    }

    int* fib = new int[n];  // dynamic array

    fib[0] = a;
    if (n > 1)
        fib[1] = b;

    int count = 2;

    while (count < n) {
        int next = fib[count - 1] + fib[count - 2];

        if (next > 100000)
            break;

        fib[count] = next;
        count++;
    }

    int evenSum = 0, oddSum = 0;

    for (int i = 0; i < count; i++) {
        if (fib[i] % 2 == 0)
            evenSum += fib[i];
        else
            oddSum += fib[i];
    }

    int diff = abs(evenSum - oddSum);

    cout << "Even Sum: " << evenSum << endl;
    cout << "Odd Sum: " << oddSum << endl;
    cout << "Positive Difference: " << diff << endl;

    delete[] fib;  // free memory

    return 0;
}
