#include <iostream>
#include <vector>

using namespace std;

// vector<int> calculateValues(vector<int>& a, vector<int>& b) {
//     vector<int> result;
    
//     for (size_t i = 0; i < a.size(); i++) {
//         int x = 0;
//         int y = a[i];
        
//         while ((x ^ y) != b[i]) {
//             x++;
//             y--;
//         }
        
//         int value = 2 * x + 3 * y;
//         result.push_back(value);
//     }   
//     return result;
// }

vector<int> solve(vector<int> &a, vector<int> &b){
    int n = a.size();
    vector<int> ans(n);
    for(int i = 0; i<n; i++){
        int d = a[i] - b[i];
        if(d<0 or d%2) ans[i] = 0;
        else{
            int x = d/2; // UPD
            int y = a[i] - x; 
            ans[i] = 2*x + 3*y;
        }
    }
    return ans;
}

int main() {
    // vector<int> a = {4, 3, 57};
    // vector<int> b = {2, 4, 49};
    vector<int>a,b;
    a.push_back(4);
    a.push_back(3);
    a.push_back(57);
    b.push_back(2);
    b.push_back(4);
    b.push_back(49);
    
    // 
    
    vector<int> result = solve(a, b);
    
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    
    cout << endl;
    
    return 0;
}
