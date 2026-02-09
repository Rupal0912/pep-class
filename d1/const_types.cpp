/*
All types of const in C++, including:
1. const variable
2. pointer to const data
3. const pointer to mutable data
4. const pointer to const data

const as parameter types in functions.
const as return types from functions.
const with class member functions.
const with class member variables.
const with references.
const with arrays.
const with dynamic memory.
const with STL containers.
const with iterators.
const with lambda expressions.
const with templates.
const with namespaces.
const with type casting.
*/

#include <iostream>
using namespace std;
// 1. const variable
void demo_const_variable()
{
    const int x = 10;
    // x = 20; // ❌ NOT allowed: modifying const variable
    cout << "Const variable: " << x << endl;
}
// 2. pointer to const data
void demo_pointer_to_const_data()
{
    int value = 30;
    const int* ptr = &value; // pointer to const data
    // *ptr = 40; // ❌ NOT allowed: modifying data through pointer
    cout << "Pointer to const data: " << *ptr << endl;
}
// 3. const pointer to mutable data
void demo_const_pointer_to_mutable_data()
{
    int value = 50;
    int* const ptr = &value; // const pointer to mutable data
    *ptr = 60;               // ✅ allowed: modifying data through pointer
    cout << "Const pointer to mutable data: " << *ptr << endl;
}
// 4. const pointer to const data
void demo_const_pointer_to_const_data()
{
    int value = 70;
    const int* const ptr = &value; // const pointer to const data
    // *ptr = 80; // ❌ NOT allowed: modifying data through pointer
    // ptr = nullptr; // ❌ NOT allowed: modifying the pointer itself
    cout << "Const pointer to const data: " << *ptr << endl;
}

int main()
{
    demo_const_variable();
    demo_pointer_to_const_data();
    demo_const_pointer_to_mutable_data();
    demo_const_pointer_to_const_data();
    return 0;
}
