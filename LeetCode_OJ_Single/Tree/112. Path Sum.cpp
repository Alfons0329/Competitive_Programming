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
    bool flg = false;
    int cur_sum = 0;
    bool hasPathSum(TreeNode* root, int sum)
    {
        return descend(root, sum);
    }
    bool descend(TreeNode* root, int& target)
    {
        if(root == NULL)
        {
            return false;
        }
        cur_sum += root->val;
            
        if(cur_sum == target && is_leaf(root))
        {
            return true;
        }
        else if(cur_sum != target && is_leaf(root))
        {
            cur_sum -= root->val;
            return false;
        }
        bool left_can = descend(root->left, target);
        bool right_can = descend(root->right, target);
        if(!left_can && !right_can)
        {
            cur_sum -= root->val;
        }
        return left_can | right_can;
    }
    bool is_leaf(TreeNode* root)
    {
        return root->left == NULL && root->right == NULL;
    }
};
