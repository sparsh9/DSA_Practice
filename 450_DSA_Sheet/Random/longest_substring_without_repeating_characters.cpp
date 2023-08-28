class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> mp;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            // if the current character is not present in the map or 
            // if it is present then update the occurence of that character with the last occurence of that character
            if (mp.count(s[right]) == 0 || mp[s[right]] < left) {
                mp[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } 
            // if the current character is already present in the map then update the left pointer to the next index of the last occurence of that character
            else {
                left = mp[s[right]] + 1;
                mp[s[right]] = right;
            }
        }
        
        return maxLength;
    }
};