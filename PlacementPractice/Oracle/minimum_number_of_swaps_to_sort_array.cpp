// Approach 1

// Function returns the
// minimum number of swaps
// required to sort the array
int minSwaps(int nums[], int n)
{
	int len = n;
	map<int, int> map;
	for (int i = 0; i < len; i++)
		map[nums[i]] = i;

	sort(nums, nums + n);

	// To keep track of visited elements. Initialize
	// all elements as not visited or false.
	bool visited[len] = { 0 };

	// Initialize result
	int ans = 0;
	for (int i = 0; i < len; i++) {

		// already swapped and corrected or
		// already present at correct pos
		if (visited[i] || map[nums[i]] == i)
			continue;

		int j = i, cycle_size = 0;
		while (!visited[j]) {
			visited[j] = true;

			// move to next node
			j = map[nums[j]];
			cycle_size++;
		}

		// Update answer by adding current cycle.
		if (cycle_size > 0) {
			ans += (cycle_size - 1);
		}
	}
	return ans;
}




// Approach 2 (Using Hash Map)


void swap(vector<int>& arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
// Return the minimum number
// of swaps required to sort
// the array
int minSwaps(vector<int> arr, int N)
{
	int ans = 0;
	vector<int> temp = arr;

	// Hashmap which stores the
	// indexes of the input array
	map<int, int> h;

	sort(temp.begin(), temp.end());
	for (int i = 0; i < N; i++) {
		h[arr[i]] = i;
	}
	for (int i = 0; i < N; i++) {
		// This is checking whether
		// the current element is
		// at the right place or not
		if (arr[i] != temp[i]) {
			ans++;
			int init = arr[i];

			// If not, swap this element
			// with the index of the
			// element which should come here
			swap(arr, i, h[temp[i]]);

			// Update the indexes in
			// the hashmap accordingly
			h[init] = h[temp[i]];
			h[temp[i]] = i;
		}
	}
	return ans;
}


