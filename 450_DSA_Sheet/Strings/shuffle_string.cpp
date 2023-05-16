// Approach 1 using the vector pairs
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int size = s.size()-1;
        vector<pair<int,char>> pair;
        for(int i=0;i<size;i++){
            pair.push_back(make_pair(indices[i],s[i]));
        }
        sort(pair.begin(),pair.end());
        string str(size,'a');
        for(int i=0;i<size;i++){
            str[i] = pair.second;
        }
        return str;
    }
};