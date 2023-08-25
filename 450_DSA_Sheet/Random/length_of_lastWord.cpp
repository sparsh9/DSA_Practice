class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]==' '){
                if(cnt>0){
                    return cnt;
                }
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};