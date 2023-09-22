// Approach : Using Priority Queue

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // first store the frequency of each task
        unordered_map<char, int> freq;

        for(char task : tasks){
            freq[task]++;
        }

        // now store the frequencies in the priority queue
        priority_queue<int> pq;

        for(auto it : freq)
            pq.push(it.second);

        // Intially time is 0
        int ans=0;

        while(!pq.empty()){
            vector<int> temp;
            // kyuki n+1 tak ke liye blocked rahenge spaces, therefore, pehle ke top n+1 freq ko use karlenge
            // followed by baaki ke elements
            for(int i=0;i<=n;i++){
                if(!pq.empty()){
                    temp.push_back(pq.top());
                    pq.pop();
                }
            }

            // ab har top freq walo ko use kar rahe hai ek ek karke,
            // agar use karne ke baad bach jaa raha hai toh wapas push kar rahe hai pq mein for
            // again getting the top freq elements in the pq in next round
            for(int i=0;i<temp.size();i++){
                temp[i]--;
                if(temp[i] > 0)
                    pq.push(temp[i]);
                
            }

            // agar pq empty hogaya toh jitne temp mein hai wahi ans mein ad honge
            if(pq.empty())
                ans += temp.size();
            // otherwise jitne ka round cycle size hai wahi rahega
            else    
                ans += n+1;
        }
        return ans;
    }
};