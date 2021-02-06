/*
Approach: Recursively move the leftmost node to the right.
Time: O(N)
Space: O(1)
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        
        // DFS
        if(root->left){
            flatten(root->left);
        }
        if(root->right){
            flatten(root->right);
        }
        
        // Cut the left subtree to the right subtree
        TreeNode* tmp_right = root->right;
        root->right = root->left;
        root->left = NULL;
        
        // Traverse down the newly-cutted left subtree and connect the end of it
        while(root->right){
            root = root->right;
        }
        root->right = tmp_right;
    }
};