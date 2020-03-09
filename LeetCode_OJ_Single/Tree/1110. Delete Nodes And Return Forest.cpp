class Solution {
public:
    vector<TreeNode*> res;
    
    TreeNode* dfs_delete(TreeNode* root, vector<int>& to_delete, bool as_root){
        if(!root){
            return NULL;
        }
        
        bool cur_node_deleted = 0;
        cur_node_deleted = find(to_delete.begin(), to_delete.end(), root -> val) != to_delete.end();
        if(as_root && !cur_node_deleted){
            res.push_back(root);
        }
        root -> left = dfs_delete(root -> left, to_delete, cur_node_deleted);
        root -> right = dfs_delete(root -> right, to_delete, cur_node_deleted);
        
        return cur_node_deleted ? NULL : root;
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        dfs_delete(root, to_delete, true);
        
        return res;
    }
};