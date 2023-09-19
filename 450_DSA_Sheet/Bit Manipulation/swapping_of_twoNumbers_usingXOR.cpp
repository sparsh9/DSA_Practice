// Function to swap two numbers using XOR operator

#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b) {
    // let a = 10, b = 20
    a = a ^ b; // -> a = 10 ^ 20  & b = 20
    b = a ^ b; // -> a = 10 ^ 20  & b = 10 ^ 20 ^ 20 = 10
    a = a ^ b; // -> a = 10 ^ 20 ^ 10 = 20 & b = 10
    // hence a = 20, b = 10
}

int main() {
    int a = 10, b = 20;
    cout << "Before swapping: " << a << " " << b << endl;
    swap(a, b);
    cout << "After swapping: " << a << " " << b << endl;
    return 0;
}