// Approach 1(Using maps - extra space)
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       unordered_map<int,int> a;
	   for(auto x: nums)
		   a[x]++;
	   for(auto z:a)
		   if(z.second==1)
			   return z.first;
	   return -1;
    }
};

// Approach 2(using sorting - no space)
class Solution {
public:
    int singleNumber(vector<int>& nums) { 
       sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i+=2)
        {
            if(nums[i]!=nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};