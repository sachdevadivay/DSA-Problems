# You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

int dfs(int** grid, int r, int c, int rows, int* cols) {
    
    if (r < 0 || r >= rows || c < 0 || c >= cols[r] || grid[r][c] == 0)
        return 0;

    
    grid[r][c] = 0;

    
    return 1
        + dfs(grid, r + 1, c, rows, cols)
        + dfs(grid, r - 1, c, rows, cols)
        + dfs(grid, r, c + 1, rows, cols)
        + dfs(grid, r, c - 1, rows, cols);
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize) {
    int maxArea = 0;

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {

            if (grid[i][j] == 1) {
                int area = dfs(grid, i, j, gridSize, gridColSize);

                if (area > maxArea)
                    maxArea = area;
            }
        }
    }

    return maxArea;
}
