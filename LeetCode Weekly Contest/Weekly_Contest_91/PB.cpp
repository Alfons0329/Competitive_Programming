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
    map<TreeNode* , TreeNode* > child_par_pair; //[child parent] pair for accessing the relationship b/w the child and parent
    set<int> visited;
    vector<int> res; //store the result

    vector<int> distanceK(TreeNode* root, TreeNode* target, int dist_K)
    {
        if(root == NULL) //return nothing if the
        {
            return vector<int>(1,0);
        }
        dfs_parent(root);
        dfs_relation(target, dist_K);
        return res;
    }
    void dfs_parent(TreeNode* root)
    {
        if(root == NULL)
        {
            return;
        }
        if(root->left)
        {
            child_par_pair[root->left] = root;
            dfs_parent(root->left);
        }
        if(root->right)
        {
            child_par_pair[root->right] = root;
            dfs_parent(root->right);
        }
    }
    void dfs_relation(TreeNode* root, int dist_K)
    {
        if(root == NULL)
        {
            return;
        }

        for(set<int>::iterator it = visited.begin(); it != visited.end(); ++it)
        {
            if(*it == root->val)//the current-visiting node has been traversed before, so we just quit
            {
                return;
            }
        }
        visited.insert(root->val); //push the current visited node for dfs mark what node has been traversed to prevent duplicated traversing

        if(dist_K == 0) //dist_K reached
        {
            res.push_back(root->val);
            return;
        }

        if(root->left) //traverse left child`
        {
            dfs_relation(root->left, dist_K - 1);
        }

        if(root->right) //traverse left child`
        {
            dfs_relation(root->right, dist_K - 1);
        }

        TreeNode* parent_node_to_traverse = child_par_pair[root];
        if(parent_node_to_traverse)
        {
            dfs_relation(parent_node_to_traverse, dist_K - 1);
        }
    }
};
