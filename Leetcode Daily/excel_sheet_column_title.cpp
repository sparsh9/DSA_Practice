class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans = "";

        while (columnNumber > 0) {
            int rem = columnNumber % 26;
            if (rem == 0) {
                ans += 'Z'; // because Z = 26, but we want Z = 0
                columnNumber = (columnNumber / 26) - 1; 
                // because if we do columnNumber = columnNumber / 26, then for 26, it will give 1, but we want 0
            } else {
                ans += (rem - 1) + 'A'; 
                // because A = 1, B = 2, C = 3, ... and not A = 0, B = 1, C = 2, ...
                columnNumber /= 26;
            }
        }

        reverse(ans.begin(), ans.end()); // because we are adding the characters in reverse order
        return ans;
    }
};



// More Better and cleaner approach

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result;
        while(columnNumber > 0)
        {
            columnNumber--;
            int remainder = columnNumber%26;
            char digit = 'A' + remainder;
            result = digit + result;
            columnNumber /=26;
        }
        return result;
        
    }
};