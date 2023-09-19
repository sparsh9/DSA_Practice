#include <iostream>
#include <vector>

using namespace std;

// set bit = 1 , therefore need to count total number of 1's in the number
int countSetBits(int n) {
    int count = 0;
    // here we are checking if the number is greater than 0 or not
    // if it is greater than 0 then we will check if the last bit is set or not
    // if it is set then we will increment the count
    // then we will right shift the number by 1 bit
    // we will do this until the number is greater than 0
    // through this we will get the total number of set bits in the number
    while (n > 0) {
        count += n & 1; // here we are checking if the last bit is set or not, if set then increment count
        n >>= 1; // here we are right shifting the number by 1 bit
    }
    return count;
}

int countBit(vector<int>& arr, int k) {
    int n = arr.size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int bitwiseOR = arr[i] | arr[j];
            int bitwiseAND = arr[i] & arr[j];
            int totalSetBits = countSetBits(bitwiseOR) + countSetBits(bitwiseAND);

            if (totalSetBits >= k) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {3,1,9,8};
    int k = 3;

    int result = countBit(arr, k);
    cout << "Number of unordered pairs with sum of set bits >= " << k << ": " << result << endl;

    return 0;
}
