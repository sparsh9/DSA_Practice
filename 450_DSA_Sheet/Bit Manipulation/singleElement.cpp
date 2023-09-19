// Make a function which takes an array and every element is repeated twice except one element. Find that element.

#include <bits/stdc++.h>
using namespace std;

int singleElement(vector<int> arr) {
    int ans = 0;
    for (int i = 0; i < arr.size(); ++i) {
        ans ^= arr[i];
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 1, 2, 3};
    cout << singleElement(arr) << endl;
    return 0;
}