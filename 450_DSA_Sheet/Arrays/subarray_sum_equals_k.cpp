
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt =0,preSum =0;
        unordered_map<int,int> map;
        map[0] = 1;
        for(int i=0;i<nums.size();i++){
            preSum += nums[i];
            int preSum_sub = preSum - k;
            cnt += map[preSum_sub];
            map[preSum] += 1;
        }
        return cnt;
    }
};