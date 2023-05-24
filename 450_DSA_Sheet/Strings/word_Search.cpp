// Approach 1 (using the dfs approach for all possible angles)
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
    for (unsigned int i = 0; i < board.size(); i++) 
        for (unsigned int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word))
                return true;
    return false;
}

bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[0])  
        return false;
    char c = board[i][j]; // making a temp variable to store its value so that it can be marked
    board[i][j] = '*'; // marked initially (Used as form of search pruning method)
    string s = word.substr(1); // deletes first char from the string
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s); // checking for next char in the string
    board[i][j] = c; // unmarked later
    return ret;
}
};