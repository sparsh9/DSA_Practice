class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Find the intersection point of the two runners.
        int tortoise = nums[0];
        int hare = nums[0];

        do {
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        } while (tortoise != hare);

        // as there is a duplicate number then there has to be a cycle,
        // till here we found the cycle and now we have to find the duplicate number
        // therefore now we have to find the entrance of the cycle from the start

        // Find the "entrance" to the cycle.
        tortoise = nums[0]; // sending tortoise to the start
        while (tortoise != hare) {
            tortoise = nums[tortoise];
            hare = nums[hare];
        }
        // now hare and tortoise are at the same position which is the duplicate number

        return hare;
    }
};