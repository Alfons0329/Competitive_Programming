/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define pb push_back
class Solution
{
public:
    vector<int> l1;
    vector<int> l2;

    bool leafSimilar(TreeNode* root1, TreeNode* root2)
    {
        get_leaf(root1, l1);
        get_leaf(root2, l2);
        if(l1.size() != l2.size())
        {
            return false;
        }
        else
        {
            for(int i = 0; i < l1.size(); i++)
            {
                if(l1[i] != l2[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    void get_leaf(TreeNode* root, vector<int>& lv)
    {
        if(root == NULL)
        {
            return;
        }
        else if(root->left == NULL && root->right == NULL)
        {
            lv.pb(root->val);
        }

        if(root->left)
        {
            get_leaf(root->left, lv);
        }
        if(root->right)
        {
            get_leaf(root->right, lv);
        }
    }

};
