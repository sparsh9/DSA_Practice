#include<unordered_map>
using namespace std;

class Solution {
public:

    // Approach 1
    bool isAnagram(string s, string t) {
        unordered_map<char,int> maps;
        unordered_map<char,int> mapt;
        for(auto &x:s)
        {
            maps[x]++;
        }

        // one of the case if size of both the strings are not equal
        if(s.size()!=t.size())
            return false;


        // Here we are checking if that key is already present in the map or not
        // and if it is then we are decrementing the value of that key by 1 from the map
        // And, when the value of that key becomes less than 0 in the map , then we return false
        for(auto &x:t)
        {
            mapt[x]--;
            if(mapt[x]<0)
                return false;
        }
        return true;
        
    }
};