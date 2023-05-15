class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int size = s.size()-1;
        unordered_map<char,int> stringPair;
        for(int i=0;i<size;i++){
            stringPair.insert({s[i],indices[i]});
        }
        
    }
};