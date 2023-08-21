/*
KMP Algorithm for String Pattern Searching
*/

#include <bits/stdc++.h>
using namespace std;

void computeLPSArray(string pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
    // lps[0] is always 0
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        // if pat[i] == pat[len] then we can extend the prefix suffix by 1
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        // if pat[i] != pat[len] then we have to check for the previous longest prefix suffix
        else 
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else 
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
    int i = 0;
    int j = 0;
    while (i < N) {
        // if pat[j] == txt[i] then increment both i and j
        if (pat[j] == txt[i]) 
        {
            j++;
            i++;
        }
        // if j == M then we have found the pattern
        if (j == M) 
        {
            cout << "Found pattern at index " << i - j << endl;
            j = lps[j - 1];
        }
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) 
        {
            if (j != 0) 
                j = lps[j - 1];
            else 
                i = i + 1;
        }
    }
}

int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(pat, txt);
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)

/*
Which is best algorithm for string matching?
The time complexity of KMP algorithm is O(n) in worst case.
The time complexity of Rabin-Karp algorithm is O(n+m) in worst case.
The time complexity of Naive algorithm is O(m(n-m+1)) in worst case.

Therefore, KMP algorithm is best algorithm among the three.
*/