/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool is_bal;
    bool isBalanced(TreeNode* root)
    {
        is_bal = 1;
        dfs_subtree(root, 0);
        return is_bal;
    }
    int dfs_subtree(TreeNode* root,int depth)
    {
        if(root == NULL)
        {
            return depth;
        }
        int left_depth = dfs_subtree(root->left, depth + 1);
        int right_depth = dfs_subtree(root->right, depth + 1);
        if(abs(left_depth - right_depth) > 1)
        {
            is_bal = 0;
        }
        int max_depth = max(left_depth, right_depth);
        left_depth = 0;
        right_depth = 0;
        return max_depth; //dont forget plus one for ascend one level to root
    }
};
