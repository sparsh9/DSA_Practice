// we start from the bottom left block, if that element is -ve then it's obvious that all the elements in its row will be -ve
// as it is in decreasing order
// also if the element is +ve, then we move to right column, until we get any -ve number.
// we get out of loop if indexes are out of bound.
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int i=m-1;
        int j=0;
		// to start from the grid[m-1][0] position
        int count=0;
        
        while(i>=0 && i<m && j>=0 && j<n){
            if(grid[i][j] < 0){
                count = count + (n-j); //when the first occurrence of a number in a row is -ve, all following numbers will be -ve. So, add their count.
                i=i-1; //then move to the above row
            }
            else{
                j=j+1; //else move to the right (i.e. to the next column)
            }
                
        }       
        
        return count;
    }
};