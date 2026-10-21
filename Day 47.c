# Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

int dfs(struct TreeNode* root, int maxValue) {
    if (root == NULL)
        return 0;

    int count = 0;

   
    if (root->val >= maxValue)
        count = 1;

    
    if (root->val > maxValue)
        maxValue = root->val;

    count += dfs(root->left, maxValue);
    count += dfs(root->right, maxValue);

    return count;
}

int goodNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;

    return dfs(root, root->val);
}
