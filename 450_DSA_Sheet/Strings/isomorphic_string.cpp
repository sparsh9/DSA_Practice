// Approach 1 using the hashtable
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap,tmap;
        for(int i=0;i<s.size();i++){
            if(smap[s[i]] && smap[s[i]] != t[i])
                return false;
            if(tmap[t[i]] && tmap[t[i]] != s[i])
                return false;
            smap[s[i]] = t[i];
            tmap[t[i]] = s[i];
        }
        return true;
    }
};