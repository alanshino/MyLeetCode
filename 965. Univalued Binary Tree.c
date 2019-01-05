/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isUnivalTree(struct TreeNode* root) {
    if (root==NULL){
        return 1;
    }else{
        if (root->left!=NULL){
            if (root->left->val!=root->val){
                return 0;
            }
        }
        if (root->right!=NULL){
            if (root->right->val!=root->val){
                return 0;
            }
        }
        return isUnivalTree(root->left)&&isUnivalTree(root->right);
    }
}
