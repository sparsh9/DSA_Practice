// TC - O((Candidates + k)Log(Candidates+k))
// SC - O(Candidates)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        long long ans=0;
        // workers with less cost will be always at top
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;

        int cnt = 0;
        int i=0;
        int j=costs.size()-1;

        // keeping count of the workers needed for the session
        while(cnt<k){
            // pushing left set of workers cost into pq1
            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            // pushing right set of workers cost into pq2
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);

            int cost1 = pq1.size()>0 ? pq1.top() : INT_MAX;
            int cost2 = pq2.size()>0 ? pq2.top() : INT_MAX;

            // checking if the least value from either side is lesser in comparison and
            // and picking that value only and when selecting, then adding it to ans and popping from the queue
            if(cost1<=cost2){

               ans += cost1;
               pq1.pop();
            }
            else{

              ans += cost2;
              pq2.pop();
            }
            // increasing the count
            cnt++;
        }

        return ans;
    }
};