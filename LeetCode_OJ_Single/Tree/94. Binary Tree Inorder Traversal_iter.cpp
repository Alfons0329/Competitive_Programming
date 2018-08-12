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
                //equivalent to inorder(cur->left);
                while(cur != NULL)
                {
                    cur = cur->left;
                    if(cur == NULL)
                    {
                        break;
                    }
                    stk.push(cur);
                }
                //equivalent to res.push_back(cur->val);
                cur = stk.top();
                //reassign
                stk.pop();
                res.push_back(cur->val);
                //equivalent to inorder(cur->right);
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
