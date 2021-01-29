// 12ms
class Solution 
{
public:
    unordered_map<TreeNode*, TreeNode*> parent_map;
    vector<int> res;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        dfs_parent(root);
        dist(target, K);
        return res;
    }
    void dfs_parent(TreeNode* root)
    {
        
        if(root -> left) // store the child-parent information for the left child node 
        {
            parent_map[root -> left] = root;
            dfs_parent(root -> left);
        }
        
        if(root -> right) // store the child-parent information for the right child node 
        {
            parent_map[root -> right] = root;
            dfs_parent(root -> right);
        }
    }
    void dist(TreeNode* target, int K)
    {
        if(target -> val < 0)// do not push_back too much redundant node
        {
            return;
        }
        
        if(K == 0)
        {
            res.push_back(target -> val);
            return; //exit immediately to prevent stackoverflow
        }
        
        target -> val = -1; // mark as done 
        
        if(parent_map.count(target)) // check for parent
        {
            dist(parent_map[target], K - 1);
        }
        
        if(target -> left)
        {
            dist(target -> left, K - 1);
        }
        
        if(target -> right)
        {
            dist(target -> right, K - 1);
        }
        
    }
};
