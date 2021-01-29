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
    int max_depth = 0;
    int maxDepth(TreeNode* root)
    {
        return dfs_depth(root, 0);
    }
    int dfs_depth(TreeNode* root, int cur_depth)
    {
        if(root == NULL)
        {
            return cur_depth;
        }
        int l_depth = dfs_depth(root->left, cur_depth + 1);
        int r_depth = dfs_depth(root->right, cur_depth + 1);
        max_depth = max(l_depth, r_depth);
        return max_depth;
    }
};
