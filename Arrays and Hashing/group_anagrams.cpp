class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string,vector<string>> mp;
         for(vector<string>::iterator t=data.begin(); t!=data.end(); ++t){
              if(isAnagram(s,))
         }

    }

    bool isAnagram(string s, string t) {
        unordered_map<char,int> maps;
        for(char x:s)
        {
            maps[x]++;
        }
        for(char x:t)
        {
            maps[x]--;
            if(maps[x]<0)
                return false;
        }
        return true;
    }
};