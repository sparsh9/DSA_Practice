class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int i, int j,int initial_color, int newColor)
    {
        // if either the conditions meets, then it returns :
        // 1) If indexes are out of bounds
        // 2) If it is already marked with new color
        // 3) If it is not the initial color or not equal to the initial color
        if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != initial_color)
        {
            return;
        }
        // Otherwise we further proceed and mark this with new color and then move in all 4 directions
        image[i][j] = newColor;
        dfs(image,i-1,j,initial_color,newColor);
        dfs(image,i+1,j,initial_color,newColor);
        dfs(image,i,j-1,initial_color,newColor);
        dfs(image,i,j+1,initial_color,newColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
    {
        int initial_color = image[sr][sc];
        dfs(image,sr,sc,initial_color,newColor);
        return image;
    }
};