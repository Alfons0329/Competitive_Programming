/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*
[90,69,null,49,89,null,52,null,null,null,null]
 */
class Solution
{
public:
    int res = INT_MAX;
    //preorder traverse to find the value of difference b/w two nodes
    vector<int> traverse_node;
    int minDiffInBST(TreeNode* root)
    {
        inorder_traverse(root);
        for(int i=0;i<traverse_node.size()-1;i++)
        {
            res=min(res,abs(traverse_node[i]-traverse_node[i+1]));
            // cout<<traverse_node[i]<<" , "<<res<<endl
        }
        return res;
    }
    void inorder_traverse(TreeNode* root)
    {
        traverse_node.push_back(root->val);
        if(root->left)
        {
            inorder_traverse(root->left);
        }
        // cout<<"Inorder  "<<root->val<<endl;
        if(root->right)
        {
            inorder_traverse(root->right);
        }
    }
};
