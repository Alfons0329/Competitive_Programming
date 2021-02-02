// Print for further stack call undetstanding
class Solution{
public:
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        
        while(cur || s.size()){
            while(cur){
                s.push(cur);
                printf("\tWhile loop, push %d, s.size() %d \n", cur->val, s.size());
                cur = cur->left;
                printf("\tWhile loop, cur = cur->left to %d\n", cur ? cur->val : -1);
            }
            cur = s.top();
            s.pop();
            printf("Pop and go right, cur %d, s.size() %d\n", cur ? cur->val : -1, s.size());
            res.push_back(cur->val);
            cur = cur->right;
            printf("cur=cur->right to %d\n", cur ? cur->val : -1);
        }
        return res;
    }
};