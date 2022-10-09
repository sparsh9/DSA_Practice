// Approach 1
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int left=0 ,right=s.size()-1;
//         while(left<right){
//             char temp;
//             temp=s[right];
//             s[right]=s[left];
//             s[left]=temp;
//             left++;
//             right--;
//         }
//         for(auto item:s)
//         cout<<item;
//     }
// };

// Approach 2
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int left=0 ,right=s.size()-1;
//         while(left<right){
//             swap(s[left++],s[right--]);
//         }
//         for(auto item:s)
//         cout<<item;
//     }
// };
