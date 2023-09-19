// Function to check if a number is a power of 2

#include <bits/stdc++.h>
using namespace std;

bool checkIfPowerOfTwo(int numb){
    // if a number is a power of 2, then it will have only one set bit
    // therefore, if we do n & (n - 1), then it will give 0 if it is a power of 2
    // otherwise it will give some other number
    return (numb & (numb - 1)) == 0;
}