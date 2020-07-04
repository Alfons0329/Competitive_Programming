/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        level_order(root, 0);
        return vector<vector<int>>(res.rbegin(), res.rend());
    }
    void level_order(TreeNode* root, int lv){
        if(!root){
            return;
        }
        if(lv == res.size()){
            res.push_back({});
        }
        
        res[lv].push_back(root -> val);
        
        if(root -> left){
            level_order(root -> left, lv + 1);
        }
        if(root -> right){
            level_order(root -> right, lv + 1);
        }
    }
}
