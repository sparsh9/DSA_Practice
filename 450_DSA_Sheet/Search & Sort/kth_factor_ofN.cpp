// Approach 1 using (space and time complexity are large even though it is accepted)
class Solution {
public:
    int kthFactor(int n, int k) {
        int cnt = 0;
        stack<int> ans;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                if (cnt == k)
                    break;
                else if (cnt < k) {
                    ans.push(i);
                    cnt++;
                }
            }
        }
        if(cnt<k)
            return -1;
        return ans.top();
    }
};

// Approach 2 using O(n) Time Complexity and O(n) Space Complexity
class Solution {
public:
    int kthFactor(int n, int k) {
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(n%i==0) c++;
            if(c==k) return i;

        }
        return -1;
    }
};