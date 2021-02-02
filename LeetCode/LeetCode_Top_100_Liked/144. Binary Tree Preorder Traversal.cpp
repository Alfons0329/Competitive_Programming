class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while(cur || s.size()){
            while(cur){
                s.push(cur);
                res.push_back(cur->val);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            cur = cur->right;        
        }
        return res;
    }
};