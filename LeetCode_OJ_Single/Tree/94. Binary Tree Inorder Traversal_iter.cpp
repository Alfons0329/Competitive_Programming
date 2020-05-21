class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> res;
        TreeNode *cur = root;
        while (cur || stk.size())
        {
            while (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            res.emplace_back(cur->val);

            cur = cur->right;
        }

        return res;
    }
};
