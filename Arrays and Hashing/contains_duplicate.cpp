#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> maps;
        for(int i=0;i<n;i++){
            if(maps.find(nums[i])==maps.end()) return true;
            maps[nums[i]] = 1;
        }
        return false;
    }

};