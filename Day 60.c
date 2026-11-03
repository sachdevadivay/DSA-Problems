# You are given an integer array nums.

In one move, you may increase the value of any single element nums[i] by 1.

Return the minimum total number of moves required so that all elements in nums become equal.

int minMoves(int* nums, int numsSize) {
    int max = nums[0];
    
    
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    
    int moves = 0;
    
    
    for (int i = 0; i < numsSize; i++) {
        moves += max - nums[i];
    }
    
    return moves;
}
