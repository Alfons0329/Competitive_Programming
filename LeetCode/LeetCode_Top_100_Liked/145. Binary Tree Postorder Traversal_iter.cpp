// Print for further stack call understanding
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while(cur || s.size()){
            while(cur){
                s.push(cur);
                res.insert(res.begin(), cur->val);
                printf("\tWhile loop, push %d, s.size() %d \n", cur->val, s.size());
                cur = cur->right;
                printf("\tWhile loop, cur = cur->right to %d\n", cur ? cur->val : -1);
            }
            cur = s.top();
            s.pop();
            printf("Pop and go left, cur %d, s.size() %d\n", cur ? cur->val : -1, s.size());
            cur=cur->left;
            printf("cur=cur->left to %d\n", cur ? cur->val : -1);
        }
        
        return res;
    }
};