#include <unordered_map>
using namespace std;

class Solution {
public:

    // Approach 1
    // bool containsDuplicate(vector<int>& nums) {
    //     // int n = nums.size();
    //     unordered_map<int,int> maps;
    //     for(auto &x:nums)
    //     {
    //         maps[x]++;
    //     }
        
    //     for(auto &z:maps)
    //     {
    //         if(z.second>=2)
    //             return true;
    //     }
        
    //     return false;
    // }

    // Approach 2
    // bool containsDuplicate(vector<int>& nums) {
    //     set<int> maps;
		
    //     maps.insert(nums.begin(),nums.end()); 
		
    //     bool ans = nums.size()!=maps.size();  
		
    //     return ans;
    // }

    // Approach 3
    // bool containsDuplicate(vector<int>& nums) {
        
    //     unordered_map<int,int> duplicate;
    //     int count ;

    //     for(int i=0;i<nums.size();i++)
    //     {
    //         duplicate[nums[i]]++;
    //     }
    //     for(auto character : duplicate)
    //     {
    //         if(character.second == 2 || character.second > 1)
    //         {
    //             return true;
    //         }
    //     }
        
    //     return false;
    // }

}; 