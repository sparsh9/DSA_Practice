// Function to print xor of numbers for a given range

#include <bits/stdc++.h>
using namespace std;

int xorOfN(int n){
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

int xorOfRange(int l, int r) {
    int xorTillL = xorOfN(l - 1);
    int xorTillR = xorOfN(r);
    return xorTillL ^ xorTillR;
}

int main() {
    int l = 5, r = 10;
    cout << xorOfRange(l, r) << endl;
    return 0;
}