#include <bits/stdc++.h>
using namespace std;

// print vector
void print(vector<int> &v)
{
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main(int argc, const char** argv) {
    vector<int> v;
    for (int i = 0; i < 10; i++)
        v.push_back(i);
    print(v);
    cout << "v.size() = " << v.size() << endl;

    v[6] = 100;
    v.erase(v.begin() + 7);

    print(v);
    cout << "v.size() = " << v.size() << endl;

    return 0;
}
