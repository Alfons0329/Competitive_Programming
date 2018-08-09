class Solution
{
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root)
    {
        stack<TreeNode*> stk;
        if(root)
        {
            stk.push(root);
            TreeNode* cur = root;
            while(stk.size() || cur != NULL)
            {
                while(cur != NULL)
                {
                    cur = cur->left;
                    if(cur == NULL)
                    {
                        break;
                    }
                    stk.push(cur);
                }
                cur = stk.top();
                stk.pop();
                res.push_back(cur->val);
                cur = cur->right;
                if(cur != NULL)
                {
                    stk.push(cur);
                }
            }
        }
        return res;
    }

};
