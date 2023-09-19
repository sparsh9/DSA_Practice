// Function to set ith bit of a Number

#include <bits/stdc++.h>
using namespace std;

int setIthBitOfNumber(int n, int i) {
    int mask = 1 << i;
    // similar to checking check set bit, we want to set bit, therefore instead of and operation we do or operation
    // this will add set bit if it was not
    int ans = n | mask;
    return ans;
}

int main() {
    int n = 5, i = 1;
    cout << setIthBitOfNumber(n, i) << endl;
    return 0;
}