# You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];

    int queue[rows * cols][2];
    int front = 0, rear = 0;

    int fresh = 0;
    int minutes = 0;

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;
            }
            else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }

    int directions[4][2] = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    while (front < rear && fresh > 0) {

        int size = rear - front;
        minutes++;

        for (int i = 0; i < size; i++) {

            int row = queue[front][0];
            int col = queue[front][1];
            front++;

            for (int j = 0; j < 4; j++) {

                int newRow = row + directions[j][0];
                int newCol = col + directions[j][1];

                if (newRow >= 0 && newRow < rows &&
                    newCol >= 0 && newCol < cols &&
                    grid[newRow][newCol] == 1) {

                    grid[newRow][newCol] = 2;
                    fresh--;

                    queue[rear][0] = newRow;
                    queue[rear][1] = newCol;
                    rear++;
                }
            }
        }
    }

    if (fresh > 0)
        return -1;

    return minutes;
}
