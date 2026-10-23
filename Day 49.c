# Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.

struct TreeNode* deleteNode(struct TreeNode* root, int key) {
    if (root == NULL)
        return NULL;

    
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {
        
        if (root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }

        
        if (root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        
        struct TreeNode* temp = root->right;

        while (temp->left != NULL) {
            temp = temp->left;
        }

        
        root->val = temp->val;

       
        root->right = deleteNode(root->right, temp->val);
    }

    return root;
}
