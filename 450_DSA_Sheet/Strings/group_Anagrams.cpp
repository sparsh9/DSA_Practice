class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // create a map of string and vector of strings
        unordered_map<string, vector<string>> m;
        for(int i=0;i<strs.size();i++){
            // sort the string
            string s = strs[i];
            sort(s.begin(), s.end());
            // push the string in the map
            m[s].push_back(strs[i]);
        }
        // create a vector of vector of strings
        vector<vector<string>> ans;
        // push the vector of strings in the ans vector
        for(auto i:m){
            ans.push_back(i.second);
        }
        return ans;
    }
};