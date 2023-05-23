class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = words.size();
        for(auto word : words){
            for(auto ch : word){
                if(allowed.find(ch) == string::npos){
                    count--;
                    break;
                }
            }
        }
        return count;
    }
};