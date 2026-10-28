# Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

  void dfs(char** grid, int row, int col, int gridSize, int* gridColSize) {
    
    if (row < 0 || row >= gridSize ||
        col < 0 || col >= gridColSize[row] ||
        grid[row][col] == '0') {
        return;
    }

    
    grid[row][col] = '0';

    
    dfs(grid, row - 1, col, gridSize, gridColSize); 
    dfs(grid, row + 1, col, gridSize, gridColSize); 
    dfs(grid, row, col - 1, gridSize, gridColSize); 
    dfs(grid, row, col + 1, gridSize, gridColSize); 
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int islands = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {

            
            if (grid[i][j] == '1') {
                islands++;

                
                dfs(grid, i, j, gridSize, gridColSize);
            }
        }
    }

    return islands;
}
