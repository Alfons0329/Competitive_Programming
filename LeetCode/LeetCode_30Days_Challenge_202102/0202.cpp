/**
Approach: Descend the tree via DFS and 
    If root is NOT within the [low, high] range, keep descending it, and concerning 2 types
    Else, connect the left and right subtree node to the respective left, right position
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root){
            return NULL;
        }
        // If root is NOT within the [low, high] range, keep descending it
        // Type 1: If current node is too high, then descend to the left side, and connect
        if(root->val > high){
            return trimBST(root->left, low, high);
        }
        else if(root->val < low){
            return trimBST(root->right, low, high);
        }
        // Else, connect the left and right subtree node to the respective left, right position
        else{
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }
        
        return root;
    }
};