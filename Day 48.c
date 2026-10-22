# Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree

int kthSmallest(struct TreeNode* root, int k) {
    struct TreeNode* stack[10000];
    int top = -1;

    while (root != NULL || top != -1) {

       
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }

       
        root = stack[top--];

        k--;

       
        if (k == 0) {
            return root->val;
        }

        
        root = root->right;
    }

    return -1;
}
