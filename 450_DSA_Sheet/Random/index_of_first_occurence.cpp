// Using Rabin Karp Algorithm

class Solution {
public:
const int d=5;
const int q=101;
    int strStr(string haystack, string needle) {
        int n=haystack.length(),m=needle.length();
        int h=1;
        for(int i=1;i<=m-1;i++) h=(h*d)%q;
        int p=0,t=0;
        for(int i=0;i<m;i++)
        {
            p=(p*d+needle[i])%q;
            t=(t*d+haystack[i])%q;
        }
        for(int i=0;i<=n-m;i++)
        {
            int j;
            if(p==t)
            {
                for(j=0;j<m;j++)
                {
                    if(haystack[i+j]!=needle[j]) break;
                }
            }
            if(j==m) return i;
            if(i<n-m)
            {
                t=((t-haystack[i]*h)*d+haystack[i+m])%q;
                if(t<0) t+=q;
            }

        }
        return -1;
        
    }
};


// Using simple 2 pointer approach

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length(),m=needle.length();
        if(m==0) return 0;
        int i=0,j=0;
        while(i<n)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                i=i-j+1;
                j=0;
            }
            if(j==m) return i-j;
        }
        return -1;
        
    }
};