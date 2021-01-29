/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    int dfs(TreeNode* root, int& res){
        if(!root) return 0;
        // if left or right has neg answer, we can just simply ignore it and use 0 to replace it
        int l = max(dfs(root -> left, res), 0);
        int r = max(dfs(root -> right, res), 0);
        res = max(l + r + root ->val, res);
        return max(l, r) + root -> val;
    }
};
