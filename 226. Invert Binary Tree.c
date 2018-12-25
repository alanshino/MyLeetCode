/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* node;
    if (root==NULL) return 0;
    node=root->left;
    root->left=root->right;
    root->right=node;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
