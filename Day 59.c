# Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.

Test cases are designed so that the answer will fit in a 32-bit integer.

int compare(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int minMoves2(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), compare);

    int median = nums[numsSize / 2];

    long long moves = 0;

    for (int i = 0; i < numsSize; i++) {
        moves += llabs((long long)nums[i] - median);
    }

    return (int)moves;
}
