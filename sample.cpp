#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'countMaximumOperations' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. STRING t
 */

int countMaximumOperations(string s, string t) {
    sort(s.begin(),s.end());
    if(s.find(t)==string::npos)
        
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int result = countMaximumOperations(s, t);

    fout << result << "\n";

    fout.close();

    return 0;
}
// to check a value in a map
