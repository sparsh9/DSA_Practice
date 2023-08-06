#include <iostream>
#include <vector>

using namespace std;

vector<int> frequencyOfMaxValue(vector<int> numbers, vector<int> q) {
    int n = numbers.size();
    vector<int> result;

    // Find the maximum value and its frequency in the entire array
    int max_val = numbers[0];
    int max_freq = 1;

    for (int i = 1; i < n; i++) {
        if (numbers[i] > max_val) {
            max_val = numbers[i];
            max_freq = 1;
        } else if (numbers[i] == max_val) {
            max_freq++;
        }
    }

    // Process each query
    for (int i = 0; i < q.size(); i++) {
        int idx = q[i] - 1; // Convert query index to 0-based index
        int segment_max = numbers[idx];
        int segment_freq = 0;

        // Traverse the segment from query index to the end of the array
        for (int j = idx; j < n; j++) {
            if (numbers[j] > segment_max) {
                segment_max = numbers[j];
                segment_freq = 1;
            } else if (numbers[j] == segment_max) {
                segment_freq++;
            }
        }

        // Append the segment frequency to the result
        result.push_back(segment_freq);
    }

    return result;
}

int main() {
    vector<int> numbers = {5, 4, 5, 3, 2};
    vector<int> q = {1, 2, 3, 4, 5};
    vector<int> result = frequencyOfMaxValue(numbers, q);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
