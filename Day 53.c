# You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int lastStoneWeight(int* stones, int stonesSize)
{
    int n = stonesSize;

    while (n > 1)
    {
        
        qsort(stones, n, sizeof(int), compare);

        
        int x = stones[n - 2];
        int y = stones[n - 1];

        if (x == y)
        {
            
            n -= 2;
        }
        else
        {
            
            stones[n - 2] = y - x;
            n--;
        }
    }

    if (n == 0)
        return 0;

    return stones[0];
}
