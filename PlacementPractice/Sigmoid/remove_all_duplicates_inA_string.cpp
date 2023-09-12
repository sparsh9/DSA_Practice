class Solution {
public:
    string removeDuplicates(string s) {
        int len = s.length();
        int i=0;
        while(i<len){
            if(s[i] == s[i+1]){
                s.erase(i,2); // erase 2 characters from index i
                // erase operation takes O(n) time.
                i = 0;
                len = s.length();
            }
            else{
                i++;
            }
        }
        return s;
    }
};





class Solution {
public:
    string removeDuplicates(string s) {
        string temp = "";
        int i = 0;
        
        while (i < s.length()) {
            if (temp.empty() || s[i] != temp.back()) {
                temp.push_back(s[i]);
            } else {
                temp.pop_back();
            }
            i++;
        }
        
        return temp;
    }
};