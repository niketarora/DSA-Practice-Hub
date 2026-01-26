class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n = board.size();
        int m = board[0].size();
        vis[row][col] = 1;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && 
               !vis[newrow][newcol] && board[newrow][newcol] == 'O')
                dfs(newrow, newcol, board, vis);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));

        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O')
                dfs(0, j, board, vis);
            if(!vis[n-1][j] && board[n-1][j] == 'O')
                dfs(n-1, j, board, vis);
        }

        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O')
                dfs(i, 0, board, vis);
            if(!vis[i][m-1] && board[i][m-1] == 'O')
                dfs(i, m-1, board, vis);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
    }
};