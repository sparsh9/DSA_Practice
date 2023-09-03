#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lessElements(const vector<int>& arr, int target) {
    return lower_bound(arr.begin(), arr.end(), target) - arr.begin();
}

int GreaterthanElement(const vector<int>& arr, int target) {
    return arr.size() - (upper_bound(arr.begin(), arr.end(), target) - arr.begin());
}

int nonOverlapping(const vector<int>& starting, const vector<int>& ending) {
    int n = starting.size();
    vector<int> st = starting;
    vector<int> end = ending;
    
    sort(st.begin(), st.end());
    sort(end.begin(), end.end());
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        int middleIntervalStart = starting[i];
        int middleIntervalEnd = ending[i];
        
        int lessThanStart = lessElements(end, middleIntervalStart);
        int greaterThanEnd = GreaterthanElement(st, middleIntervalEnd);
        
        ans += lessThanStart * greaterThanEnd;
    }
    
    return ans;
}

int main() {
    // vector<int> starting = {1, 3, 5};
    vector<int> starting;
    starting.push_back(1);
    starting.push_back(2);
    starting.push_back(3);
    starting.push_back(4);
    // vector<int> ending = {2, 4, 6};
    vector<int> ending;
    ending.push_back(1);
    ending.push_back(2);
    ending.push_back(3);
    ending.push_back(4);

    int result = nonOverlapping(starting, ending);
    
    cout << "Result: " << result << endl;
    
    return 0;
}
