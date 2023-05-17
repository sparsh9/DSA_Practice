// Approach 1 using backtracking
// Logic for the backtrack function is below :
// 1. The `backtrack` function is defined as a helper function to perform the backtracking process. It takes the following parameters:
//    - `tiles`: The string of tiles representing the current combination.
//    - `level`: The current level of the backtracking process.
//    - `count`: A reference to an integer representing the count of valid combinations.

// 2. Inside the `backtrack` function, the `count` is incremented by 1. This is done to count each valid combination encountered during the backtracking process.

// 3. The function then starts a loop from `level` to the end of the `tiles` string. This loop iterates over the possible choices for the current position in the combination.

// 4. At each iteration, it checks if the current character (`tiles[i]`) is the same as the character at the `level` position. If it is, it skips this iteration using the `continue` statement. This is done to avoid counting duplicate combinations.

// 5. If the current character is different from the character at the `level` position, it performs a swap between `tiles[i]` and `tiles[level]`. This swap ensures that the current character is placed at the `level` position in the combination.

// 6. After the swap, the `backtrack` function is called recursively with an incremented `level` and the updated `tiles` string. This allows the backtracking process to move on to the next level and explore the remaining choices.

// 7. The recursion continues until the base case is reached, which is when `level` equals the length of the `tiles` string.


class Solution {
    
    void backtrack(string tiles, int level, int &count)
    {
        count++;
        for(int i=level; i<tiles.length(); i++){
            
            if(i!=level && tiles[i]==tiles[level])
                continue;   // to skip same characters
            swap(tiles[i], tiles[level]);
            backtrack(tiles, level+1, count);
        }
    }
    
public:
    int numTilePossibilities(string tiles) {
        
        int count=-1;
        sort(tiles.begin(), tiles.end()); 
        
        backtrack(tiles, 0, count); //level = susbstring length
        
        return count;
    }
};