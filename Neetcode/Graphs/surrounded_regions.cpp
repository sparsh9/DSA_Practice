class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(),n=m ? board[0].size() : 0;
        if(m==0 || n==0) return;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                setX(board,i,j);
        }
        for(int i=0;i<m;i++){
            cout<<board[i][i];
        }
    }

    void setX(vector<vector<char>>& board ,int i,int j){
        int m = board.size(),n=board[0].size();
        if(i<0 || i==m || j<0 || j==n || board[i][j]=='0'){
            return; 
        }     
        board[i][j] = 'X';
        setX(board,i+1,j);
        setX(board,i-1,j);
        setX(board,i,j+1);
        setX(board,i,j-1);
    }
};