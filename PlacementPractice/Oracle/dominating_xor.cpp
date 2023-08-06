// Approach 1 

int findCount(int arr[], int N)
{
	// For storing number of pairs
	int ans = 0;

	// For storing count of numbers
	int bits[32] = { 0 };

	// Iterate from 0 to N - 1
	for (int i = 0; i < N; i++) {

		// Find the most significant bit
		int val = log2l(arr[i]);

		ans += bits[val];
		bits[val]++;
	}
	return N * (N - 1) / 2 - ans;
}



// Approach 2

// Function to count pairs that
// satisfy the above condition.
int cntPairs(int arr[], int N)
{
 
    // Stores the count
    // of pairs
    int res = 0;
 
    // Stores the count of array
    // elements having same
    // positions of MSB
    int bit[32] = { 0 };
 
    // Traverse the array
    for (int i = 0; i < N; i++) {
 
        // Stores the index of
        // MSB of array elements
        int pos
            = log2(arr[i]);
        bit[pos]++;
    }
 
    // Calculate number of pairs
    for (int i = 0; i < 32; i++) {
        res += (bit[i]
                * (bit[i] - 1))
               / 2;
    }
    res = (N * (N - 1)) / 2 - res;
 
    return res;
}
