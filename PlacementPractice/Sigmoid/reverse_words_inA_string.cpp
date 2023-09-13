class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        vector<string> words;
        string temp = "";

        for(int i =0;i<n;i++){
            if(s[i] == ' '){
                if(temp != ""){
                    words.push_back(temp);
                    temp = "";
                }
            }
            else{
                temp += s[i];
            }
        }
        if(temp != ""){
            words.push_back(temp);
        }

        string ans = "";
        for(auto it = words.rbegin();it!=words.rend();it++){
            ans += *it;
            ans += " ";
        }
        ans.pop_back(); // remove last space character
        return ans;
    }
};