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
    map<TreeNode* , TreeNode* > parent_pair; //[child parent] pair for accessing the relationship b/w the child and parent
    set<TreeNode*> visited;
    vector<int> res; //store the result

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K)
    {
        for(map<TreeNode*, TreeNode*>iterator::it)
    }
    void dfs_parent(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        if(root -> left)
        {
            parent_pair[root -> left] = root;
        }
        if(root -> right)
        {
            parent_pair[root -> left] = root;

        }
    }
    void dfs_relation()
    {

    }
};
