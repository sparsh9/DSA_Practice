// Approach 1 (Using Hash Table)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int num : nums) {
            if (++m[num] > floor(nums.size() / 2)) {
                return num;
            }
        }
        return 0;
    }
};

// Approach 2 (Using moore's voting algorithm)
// majority element is +1, rest all are -1, so the final sum should be >1
// try to find the sum>1 with the number. Add 1 if same number subtract 1 if different
/*
Think of this array as a collection of votes from the voters for different political parties.
Now as we know the party which has >50% votes can form the government.

So , our above question is analogous to this situation.
Now , if we are certain that one party has > 50% votes . Then , if :

We increment a count variable every time we see the vote from the majority party and decrement it whenever a vote from some other party is occured , we can guarantee that ,
count>0.

Using the above logic ,

Create a count=0 and a majority variable that stores the current majority element.
Traverse the array , and if count =0 , then store the current element as the majority element and increment the count.
Else , if the current element is equal to the current majority element , increment count , else decrement it.
At the end return the majority element.
This approach works because ,

We simply know that the majority element has a frequency greater than half of the total elements.
So , the value of count > 0.
But whenever it becomes 0 , it means that till now the majority element has either not occured , 
or if it has then the its frequency is equal to the sum of frequency of rest of the others. 
So , the next element will be the majority element till now . But eventually by the end , 
the final answer will always be the majority element of the array , 
as when the "count" becomes 0 for the final time , the next element will be the majority element.
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        

        int majorityElement, count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(count == 0)
                majorityElement=nums[i];

            if(nums[i]==majorityElement)
                count++;
            else 
                count--;            
        }
        return majorityElement;
    }
};