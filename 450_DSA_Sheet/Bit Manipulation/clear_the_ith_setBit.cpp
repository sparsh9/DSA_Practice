// Function to clear ith bit of a Number

#include <bits/stdc++.h>
using namespace std;

int clearIthBitOfNumber(int n, int i) {
    int mask = 1 << i;
    // similar to checking check set bit, we want to clear bit, therefore instead of or operation we do and operation
    // this will clear set bit if it was set
    int ans = n & (~mask);
    return ans;
}

int main() {
    int n = 5, i = 2;
    cout << clearIthBitOfNumber(n, i) << endl;
    return 0;
}