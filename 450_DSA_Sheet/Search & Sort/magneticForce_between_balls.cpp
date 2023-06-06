// Approach (using Binary Search)
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        // l is set to 0 (minimum distance) and r is set to the max distance.
        // We are performing the binary search on the distance and not the indexes.
        int l = 0, r = position.back() - position.front();
        while (l < r) {
            int mid = r - (r - l) / 2;
            // count the number of balls that can be placed with a distance of mid between them. 
            // If the count is greater than or equal to m, it means that we can place m balls with a distance of mid, so we update l to mid. 
            // Otherwise, we update r to mid - 1.
            if (count(position, mid) >= m)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
private:
    // The count function is used to calculate the number of balls that can be placed with a given distance d between them. 
    // It iterates through the sorted position array and counts the number of intervals that have a distance greater than or equal to d. 
    // It maintains a counter ans to keep track of the number of balls and updates the current position cur whenever a new interval with a sufficient distance is encountered.
    int count(vector<int>& position, int d) {
        int ans = 1, cur = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - cur >= d) {
                ans++;
                cur = position[i];
            }
        }
        return ans;
    }
};