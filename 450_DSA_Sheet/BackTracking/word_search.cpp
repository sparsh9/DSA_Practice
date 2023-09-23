class Solution {
public:
    bool isPossible(vector<vector<char>>& board, int i, int j, string word){
        // base cases
        if(word.size() == 0){
            return true;
        }
        // here only we are checking if the char at this block matches with the char of the word
        if(i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j] != word[0]){
            return false;
        }

        // continously checking for the first char of word, hence deleting its first char for next iteration
        string s = word.substr(1);

        // recursive action
        char c = board[i][j];
        board[i][j] = '*'; // marking this bcz when we do recursive in all directions, it should not be caught again, hence kind of marking it as visited
        bool ans = isPossible(board,i-1,j,s) || isPossible(board,i+1,j,s) || isPossible(board,i,j-1,s) || isPossible(board,i,j+1,s);
        board[i][j] = c; // reseting it back to original

        return ans;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(isPossible(board,i,j,word)){
                    return true;
                }
            }
        }
        return false;
    }
};