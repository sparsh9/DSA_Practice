// Function to print xor of all numbers from (1 to n)

#include <bits/stdc++.h>
using namespace std;

int xorOfAllNumbers(int n) {
    if (n % 4 == 0) {
        return n;
    } 
    else if (n % 4 == 1) {
        return 1;
    } 
    else if (n % 4 == 2) {
        return n + 1;
    } 
    else {
        return 0;
    }
}

int main() {
    int n = 5;
    cout << xorOfAllNumbers(n) << endl;
    return 0;
}