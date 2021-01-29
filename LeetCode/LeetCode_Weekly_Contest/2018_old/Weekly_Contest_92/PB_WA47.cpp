/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    map<TreeNode*, TreeNode*> leaf_par;
    map<TreeNode*, int>leaf_depth;
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        if(!root->left && !root->right)
        {
            return root;
        }
        dfs_leaf(root, 0);
        TreeNode* res_node;
        unsigned int max_d = 0;
        for(map<TreeNode*, TreeNode*>::iterator it = leaf_par.begin(); it != leaf_par.end(); ++it)
        {
            printf("%d has parent %d\n",it->first->val, it->second->val);
            if(leaf_depth[it->first] > max_d && leaf_par[it->first]->left && leaf_par[it->first]->right)
            {
                max_d = leaf_depth[it->first];
                res_node = leaf_par[it->first];
            }
            else if(leaf_depth[it->first] && (leaf_par[it->first]->left == NULL || leaf_par[it->first]-> == NULL))
            {
                max_d = leaf_depth[it->first];
                res_node = it->first;
            }
        }
        return res_node;
    }
    void dfs_leaf(TreeNode* root, int depth)
    {
        printf("visit %d with depth %d \n", root->val, depth);
        if(root->left)
        {
            leaf_par[root->left] = root;
            dfs_leaf(root->left, depth + 1);
        }

        if(root->right)
        {
            leaf_par[root->right] = root;
            dfs_leaf(root->right, depth + 1);
        }

        if(!root->left && !root->right)
        {
            printf("reach end depth %d\n", depth);
            leaf_depth[root] = depth;
            return;
        }
    }
};
