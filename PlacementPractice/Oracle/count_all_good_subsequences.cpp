#include <bits/stdc++.h>
#define watch(x)                    \
    for (int i = 0; i < sz(x); i++) \
    cout << x[i] << "\n"
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
#define ll long long int
#define ld long double
#define show(x) cout << x[i] << " "
using namespace std;

#define MAX 100000
#define MOD 1000000007

// Function to generate a triangle of binomial coefficients up to given frequency
vector<vector<long long>> makeTriangle(long long freq)
{
    vector<vector<long long>> triangle(freq + 1, vector<long long>(freq + 1, 0));
    // Initialize first row of the triangle
    triangle[0][0] = 1;

    // Initialize first column of the triangle
    for (int i = 1; i <= freq; i++)
        triangle[i][0] = 1;

    // Fill the triangle using the recursive formula for binomial coefficients
    for (int i = 1; i <= freq; i++)
        for (int j = 1; j <= i; j++)
            // forming a dp table of (max_frequency) X (max_frequency) 
            triangle[i][j] = (triangle[i - 1][j - 1] + triangle[i - 1][j]) % MOD;

    return triangle;
}

// Function to count the number of good subsequences
long long countGoodSubsequences(string s)
{
    // Map to store character frequencies in the string
    unordered_map<char, int> mp;
    for (auto &x : s)
        mp[x]++;
    
    long long res = 0, max_freq = 0;

    // Find the maximum frequency of any character in the string
    for (auto &x : mp)
        max_freq = max(max_freq, (long long)x.second);


    // Generate a triangle of binomial coefficients up to the maximum frequency
    vector<vector<long long>> triangle = makeTriangle(max_freq);

    // Calculate the number of good subsequences for each frequency
    for (int i = max_freq; i >= 1; i--)
    {
        long long temp = 1;
        for (auto &x : mp)
        {
            // (1+(n1)C(k)) * 1+(n2)C(k)) * 1+(n3)C(k)) * 1+(n4)C(k)) * ......
            temp = temp * (1 + triangle[x.second][i]) % MOD;
        }
        // {(1+(n1)C(k)) * 1+(n2)C(k)) * 1+(n3)C(k)) * 1+(n4)C(k)) * ...} - 1
        res = (res + temp - 1 + MOD) % MOD;
    }

    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    string s;
    cin >> s;

    cout << countGoodSubsequences(s) << "\n";
    return 0;
}
