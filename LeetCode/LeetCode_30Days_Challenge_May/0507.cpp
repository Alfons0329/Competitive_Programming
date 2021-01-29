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
    pair<TreeNode*, int> p; // pair < parent, depth >
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, root, x, 0); // x
        pair<TreeNode*, int > p1 = p;
        dfs(root, root, y, 0); // y
        pair<TreeNode*, int > p2 = p;
        
        return p1.first != p2.first && p1.second == p2.second;
    }
    
    void dfs(TreeNode* root, TreeNode* parent /*parent of current node*/, int x, int d /*current depth*/){
        if(!root){
            return;
        }
        
        if(x == root -> val){
            p = {parent, d};
        }
        
        dfs(root -> left, root, x, d + 1);
        dfs(root -> right, root, x, d + 1);
    }
