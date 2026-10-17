# Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.

#include <limits.h>
#include <stdbool.h>

bool checkBST(struct TreeNode* root, long min, long max) {

    
    if (root == NULL) {
        return true;
    }

    
    if (root->val <= min || root->val >= max) {
        return false;
    }

   
    return checkBST(root->left, min, root->val) &&
           checkBST(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {

    return checkBST(root, LONG_MIN, LONG_MAX);
}
