// Approach 1 with O(n) space and O(n) time complexity
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        vector<int> v;
        for(int i=0;i<s.size();i++){
            if(s[i] == '[')
                v.push_back(i);
        } 
        int idx=0; // keeps track of the index of the '[' in the array to balance the imbalance by ']'
        int ans = 0; // counts the number of swaps
        int count = 0; // counts the balance of the string array

        for(int i=0;i<s.size();i++){
            if(s[i] == '['){
                idx++;
                count++;
            }
            else{
                count--;
                if(count<0){
                    ans += v[idx]-i; // gets the total number of swaps needed to switch
                    swap(s[i],s[v[idx]]);
                    count = 1;
                    idx++;
                }
            }
        }
        return ans;
    }
};

// Approach 2 More optimal to the above without using the extra space
class Solution{   
public:
    int minimumNumberOfSwaps(string s){
        int ans = 0;
        int open=0,close=0;
        int fault=0;
        for(int i=0;i<=s.size();i++){
            if(s[i] == ']'){
                close++;
                fault = close-open;
            }
            else{
                open++;
                if(fault>0){
                    ans += fault;
                    fault--;
                }
            }
        }
        return ans;
    }
};

