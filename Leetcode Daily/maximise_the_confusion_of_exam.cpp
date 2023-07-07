// Approach (Using Sliding window and 2 pointer approach)
class Solution {
public:
    int solve(string &s,char b,int &k){
       int left=0,res=0,size=s.size(),cnt=0;
      for(int right=0;right<size;right++){
            if(s[right]==b)
                cnt++;
            // when there is more than k values of b in our window, we decrease its value
            // by reducing the window and hence decreasing the number of b's in our window
            while(cnt>k){
                if(s[left]==b)
                    cnt--;
                left++;
            }
            // right-left+1 is the window size, 
            // we return the maximum of current window size and result till now
            res=max(right-left+1,res);
        }
        return res;
    }
    int maxConsecutiveAnswers(string s, int k) {
        // max substring of T's with atmost k F's and 
        // max substring of F's with atmost k T's
        // we take the max of both the conditions
      return max(solve(s,'F',k),solve(s,'T',k));  
    }
};