class Solution {
public:
    void reverseString(vector<char>& s) {
        int left=0 ,right=s.size()-1;
        for(int i=0;i<s.size();i++){
            char temp;
            temp=s[right];
            s[right]=s[left];
            s[left]=temp;
            left++;
            right--;
        }
        for(auto item:s)
        cout<<item;
    }
};
