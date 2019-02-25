class Solution 
{
public:
    bool hasPathSum(TreeNode* root, int sum) 
    {
        if(root == NULL)
        {
            return false; 
        }
        if(root != NULL && root ->left == NULL && root -> right == NULL)
        {
            return root -> val == sum;
        }
        return hasPathSum(root -> left, sum - root->val) || hasPathSum(root -> right, sum - root -> val);
    }
};