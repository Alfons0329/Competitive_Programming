class Solution {
public:
    int n;
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        n = arr.size();
        return dfs(root, arr, 0);
    }
    bool dfs(TreeNode* root,vector<int>& arr,int idx){
        if(root -> val != arr[idx]) return false;
        else if(idx == n - 1) return !root -> left && !root -> right;
        
        bool tmp = false;
        if(root -> left) tmp |= dfs(root -> left, arr, idx + 1);
        if(root -> right) tmp |= dfs(root -> right, arr, idx + 1);
        return tmp;
    }
};
