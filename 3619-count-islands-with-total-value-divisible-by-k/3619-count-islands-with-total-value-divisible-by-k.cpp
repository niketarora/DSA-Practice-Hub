class Solution {
private:
    void dfs(std::vector<std::vector<int>>& grid, int r, int c, long long& currentSum) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) {
            return;
        }
        
        currentSum += grid[r][c];
        grid[r][c] = 0; 
        dfs(grid, r + 1, c, currentSum);
        dfs(grid, r - 1, c, currentSum);
        dfs(grid, r, c + 1, currentSum);
        dfs(grid, r, c - 1, currentSum);
    }

public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] > 0) { 
                    long long currentSum = 0;
                    dfs(grid, i, j, currentSum);
                    
                    if (k != 0 && currentSum % k == 0) {
                        islandCount++;
                    }
                }
            }
        }
        
        return islandCount;
    }
};