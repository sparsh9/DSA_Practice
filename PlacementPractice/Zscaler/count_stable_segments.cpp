#include <iostream>

int CountStableSegments(int capacity[], int n) {
    int count = 0;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i + 1; j < n; ++j) {
            sum += capacity[j - 1];
            if (capacity[i] == capacity[j] && sum == capacity[i])
                ++count;
        }
    }

    return count;
}

int main() {
    int capacity[] = {9,3,3,3,9};
    int n = sizeof(capacity) / sizeof(capacity[0]);

    int stableSegments = CountStableSegments(capacity, n);
    std::cout << "Number of stable segments: " << stableSegments << std::endl;

    return 0;
}
