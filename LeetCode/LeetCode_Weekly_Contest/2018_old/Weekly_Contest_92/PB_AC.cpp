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
    map<TreeNode*, node_info> node_info_map_2;
    TreeNode* deepest_node;
    TreeNode* deepest_2nd_node;
    TreeNode* res;
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        if(root->left == NULL && root->right == NULL) //if tree size is 1 just return the root
        {
            return root;
        }
        dfs_information(root, 0);
        //find the 1st deepest leaf
        int deepest = 0;
        deepest_node = deepest_2nd_node = NULL;
        node_info_map_2 = node_info_map;
        for(map<TreeNode* , node_info>::iterator it = node_info_map_2.begin(); it != node_info_map_2.end(); it++)
        {
            if(it->first->left == NULL && it->first->right == NULL)
            {
                if(it->second.depth > deepest)
                {
                    deepest = it->second.depth;
                    deepest_node = it->first;
                }
            }
        }

        node_info_map_2.erase(deepest_node);

        //find the 2nd deepest leaf if same depth, then update the sceond one for the LCA
        for(map<TreeNode* , node_info>::iterator it = node_info_map_2.begin(); it != node_info_map_2.end(); it++)
        {
            if(it->first->left == NULL && it->first->right == NULL)
            {
                if(it->second.depth == deepest)
                {
                    deepest = it->second.depth;
                    deepest_2nd_node = it->first;
                }
            }
        }
         //if no other deepest with same depth, do not do LCA, since the deepest_node "ITSELF" is the smallest subtree containing the deepest_node
        if(deepest_2nd_node == NULL)
        {
            return deepest_node;
        }
        climbup_LCA(deepest_node, deepest_2nd_node);
        return res;
    }
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
