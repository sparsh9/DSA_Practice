class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;
       vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++){
                string temp=strs[i];
                sort(strs[i].begin(),strs[i].end());
                mp[strs[i]].push_back(temp);
        }
        for(auto it=mp.begin();it!=mp.end();it++){
                ans.push_back(it->second);
        }
        return ans;
    }
    
};