# Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int *p1 = *(int **)a;
    int *p2 = *(int **)b;

    long long d1 = (long long)p1[0] * p1[0] +
                   (long long)p1[1] * p1[1];

    long long d2 = (long long)p2[0] * p2[0] +
                   (long long)p2[1] * p2[1];

    if (d1 < d2)
        return -1;
    if (d1 > d2)
        return 1;

    return 0;
}

int** kClosest(int** points, int pointsSize, int* pointsColSize,
               int k, int* returnSize, int** returnColumnSizes)
{
    
    qsort(points, pointsSize, sizeof(int *), compare);

    
    *returnSize = k;

    
    *returnColumnSizes = (int *)malloc(k * sizeof(int));

    
    int **result = (int **)malloc(k * sizeof(int *));

    for (int i = 0; i < k; i++)
    {
        (*returnColumnSizes)[i] = 2;

        result[i] = (int *)malloc(2 * sizeof(int));

        result[i][0] = points[i][0];
        result[i][1] = points[i][1];
    }

    return result;
}
