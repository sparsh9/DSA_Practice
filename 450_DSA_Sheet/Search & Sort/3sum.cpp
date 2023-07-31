// Approach 1 using Set as O(n) S.C and O(n^2) as T.C
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort the input array in ascending order
        sort(nums.begin(), nums.end());
        
        // Step 2: Initialize a set to store unique triplets
        set<vector<int>> set;
        
        // Step 3: Iterate over the array and fix the first element of the triplet
        for(int i = 0; i < n - 2; i++){
            int low = i + 1; // Pointer to the second element (left)
            int high = n - 1; // Pointer to the third element (right)
            
            // Step 4: Two-pointer approach to find the remaining two elements of the triplet
            while(low < high){
                int sum = nums[i] + nums[low] + nums[high];
                
                if(sum < 0){ // If the sum is less than 0, move the left pointer to the right
                    low++;
                }
                else if(sum > 0){ // If the sum is greater than 0, move the right pointer to the left
                    high--;
                }
                else{ // If the sum is equal to 0, we found a triplet
                    set.insert({nums[i], nums[low], nums[high]});
                    low++;
                    high--;
                }
            }
        }
        
        // Step 5: Convert the set of unique triplets to a vector
        vector<vector<int>> output;
        for(auto it : set){
            output.push_back(it);
        }
        
        // Step 6: Return the vector of unique triplets
        return output;
    }
};



// Approach 2 using 2 pointer with O(n^2) as T.C and O(1) as S.C
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end());    //Sorted Array
        if(nums.size() < 3){    //Base case 1
            return {};
        }
        if(nums[0] > 0){        //Base case 2
            return {};
        }
        vector<vector<int>> answer;
        for(int i = 0 ; i < nums.size() ; ++i){     //Traversing the array to fix the number.
            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
                continue;
            }
            int low = i + 1 , high = nums.size() - 1;   //Make two pointers high and low, and initialize sum as 0.
            int sum = 0;
            while(low < high){                          //Search between two pointers, just similiar to binary search.
                sum = nums[i] + nums[low] + nums[high];
                if(sum > 0){   //If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
                    high--;
                } else if(sum < 0){ //If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
                    low++;
                } else {
                    answer.push_back({nums[i] , nums[low] , nums[high]});  //we have found the required triplet, push it in answer vector
                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
                    while(low < high && nums[low] == last_low_occurence){   // It runs until we get the last occurence of low and low must be < high
                        low++;
                    }
                    while(low < high && nums[high] == last_high_occurence){
                        high--;
                    }
                }
            }
        }
        return answer;      //Return the answer vector.
    }
};