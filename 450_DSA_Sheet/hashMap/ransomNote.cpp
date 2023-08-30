class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> r,m;

        // hashing all char from ransomNote
        for(int i=0;i<ransomNote.size();i++){
            r[ransomNote[i]]++;
        }

        // hashing all char from magazine
        for(int i=0;i<magazine.size();i++){
            m[magazine[i]]++;
        }

        // checking if all char from ransomNote is present in magazine
        for(int i=0;i<ransomNote.size();i++){
            if(m[ransomNote[i]]<r[ransomNote[i]]){
                return false;
            }
        }
        return true;
    }
};