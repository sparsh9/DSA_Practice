// Approach : Rotate String and get the rotation number when the string gets repeated

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string g = s;
        int r = s.size();
        queue<char> q1,q2;

        for(int i=0;i<s.size();i++)
            q1.push(s[i]);
        
        for(int i=0;i<s.size();i++)
            q2.push(s[i]);
        
        while(r--){
            char temp = q1.front();
            q1.pop();
            q1.push(temp);

            if(q1 == q2)
                break;
        }
        if(r == 0)
            return false;
        else
            return true;
    }
};



// Approach : Using KMP Algorithm

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> lps(n,0);
        int i=1,len=0;
        while(i<n){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len != 0)
                    len = lps[len-1];
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        int res = lps[n-1];
        return (res > 0 && n % (n-res) == 0);
    }
};




// Approach : Using Robin Karp Algorithm

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        int p = 31;
        int m = 1e9 + 7;
        vector<long long> p_pow(n);
        p_pow[0] = 1;
        for(int i=1;i<n;i++)
            p_pow[i] = (p_pow[i-1] * p) % m;
        
        vector<long long> h(n+1,0);
        for(int i=0;i<n;i++)
            h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;
        
        for(int len=1;len<=n;len++){
            long long h_s = (h[len] - h[0] + m) % m;
            bool flag = true;
            for(int i=len;i<n;i+=len){
                long long curr = (h[i+len] - h[i] + m) % m;
                if(curr != h_s)
                    flag = false;
            }
            if(flag)
                return true;
        }
        return false;
    }
};