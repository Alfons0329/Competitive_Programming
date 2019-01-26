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
    int res = 0;
    int distributeCoins(TreeNode* root) 
    {
        dfs(root);
        return abs(res);
    }
    int dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int L = dfs(root -> left);
        int R = dfs(root -> right);
        res += abs(L) + abs(R);
        return L + R + (root -> val - 1);
    }
};