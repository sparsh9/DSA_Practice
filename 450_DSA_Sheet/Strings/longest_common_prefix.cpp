// Approach 1 (maching the string subparts)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string ans = "";
        string first = strs[0],last = strs[n-1];
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i] == last[i])
                ans.push_back(first[i]);
            else
                return ans;
        }
        return ans;
    }
};