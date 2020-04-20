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
    int idx;
    TreeNode* bstFromPreorder(vector<int>& p) {
        idx = 0;
        return create(INT_MAX, INT_MIN, p);
    }
    
    TreeNode* create(int mx, int mn, vector<int>& p){
        // used out all the nodes
        if(idx >= p.size()){
            return NULL;
        }
        // get node value
        int val = p[idx];
        // node value not in range
        if(val > mx || val < mn){
            return NULL;
        }
        idx++;
        
        TreeNode* new_node = new TreeNode(val);
        new_node -> left = create(val, mn, p);
        new_node -> right = create(mx, val, p);
        
        return new_node;
    }
};