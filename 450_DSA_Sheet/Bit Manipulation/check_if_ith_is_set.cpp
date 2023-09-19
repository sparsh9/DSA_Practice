// Function to check if ith bit of a number n is set or not

#include <bits/stdc++.h>
using namespace std;

bool checkIfIthBitIsSet(int n, int i) {
    int mask = 1 << i; // 1 << i means 1 is shifted i times to the left
    bool ans = (n & mask) != 0; // we simply do and operation of n and mask and check if it is not equal to 0, wherein
    // if there is set bit then it will return 1 and if there is no set bit then it will return 0
    return ans;
}

int main() {
    int n = 5, i = 1;
    cout << checkIfIthBitIsSet(n, i) << endl;
    return 0;
}