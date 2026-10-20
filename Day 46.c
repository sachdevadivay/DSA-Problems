# A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path.

#include <limits.h>

int maxSum;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int gain(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    
    int left = max(0, gain(root->left));
    int right = max(0, gain(root->right));

    
    int currentPath = root->val + left + right;

    
    maxSum = max(maxSum, currentPath);

    
    return root->val + max(left, right);
}

int maxPathSum(struct TreeNode* root) {
    maxSum = INT_MIN;

    gain(root);

    return maxSum;
}
