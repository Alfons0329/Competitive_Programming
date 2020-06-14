/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> vec;
    vector<int> vec2;
    TreeNode* increasingBST(TreeNode* root)
    {
        dfs(root);

        TreeNode* new_root = new TreeNode(vec[0]);
        TreeNode* prev = new_root;
        TreeNode* cur;

        for(int i = 1; i < vec.size(); i++)
        {
            cur = new TreeNode(vec[i]);
            prev->left = NULL;
            prev->right = cur;
            prev = cur; //move
        }
        dfs(new_root);
        return new_root;
    }
    void dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        dfs(root->left);
        vec.push_back(root->val);
        dfs(root->right);
    }
