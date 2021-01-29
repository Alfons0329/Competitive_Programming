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
    struct node_info
    {
        TreeNode* parent;
        int depth;
    };
    map<TreeNode*, node_info> node_info_map;
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* node_p, TreeNode* node_q)
    {
        dfs_information(root, 0);
        node_info_map[root].parent = root; //for the root itself without runtime error
        res = root; //initialize
        climbup_LCA(node_p, node_q);
        return res;
    }
    //traverse the tree first to find the child-parent pair
    void dfs_information(TreeNode* root, int depth)
    {
        if(root == NULL)
        {
            return;
        }
        node_info_map[root].depth = depth;
        if(root->left)
        {
            node_info_map[root->left].parent = root;
            dfs_information(root->left, depth + 1);
        }
        if(root->right)
        {
            node_info_map[root->right].parent = root;
            dfs_information(root->right, depth + 1);
        }
    }
    //climb up to find the LCA, using depth comparison algorithm
    void climbup_LCA(TreeNode* node_p, TreeNode* node_q)
    {
        if(node_info_map[node_p].parent == node_info_map[node_q].parent)
        {
            res = node_info_map[node_p].parent;
            return;
        }
        else if(node_info_map[node_p].parent == node_q)
        {
            res = node_q;
            return;
        }
        else if(node_info_map[node_q].parent == node_p)
        {
            res = node_p;
            return;
        }

        else if(node_info_map[node_p].depth > node_info_map[node_q].depth) //the one who is lower has to climb up one depth
        {
            climbup_LCA(node_info_map[node_p].parent, node_q);
        }
        else
        {
            climbup_LCA(node_p, node_info_map[node_q].parent);
        }
    }
};
