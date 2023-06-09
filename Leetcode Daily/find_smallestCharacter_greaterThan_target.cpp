class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
       int n=letters.size();
       
       // base conditions
       if(target >= letters[n-1]) return letters[0];

       int s=0;
       int e=n-1;
       while(s<=e){
        int mid = s + (e-s)/2;
        if(letters[mid]>target) e=mid-1;
        else s=mid+1;
       }
       return letters[s]; 
    }
};