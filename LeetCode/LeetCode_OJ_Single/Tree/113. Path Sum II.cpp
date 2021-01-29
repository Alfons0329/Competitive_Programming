class Solution 
{
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        vector<int> tmp;
        dfs(root, sum, tmp);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<int>& tmp)
    {
        if(root == NULL)
        {
            return; 
        }
            
        tmp.push_back(root -> val); // push the non leaf node into the stack(now with vector)
        
        if(root != NULL && root ->left == NULL && root -> right == NULL) //if it is leaf node
        {
            if(root -> val == sum) // check if satisfies the criterium
            {
                res.push_back(tmp);
            }
            tmp.pop_back(); // pop the leaf node from the stack since such node is the end of one root-to-leaf path    
            return;
        }
        dfs(root -> left, sum - root->val, tmp); //descend for the left subtree
        dfs(root -> right, sum - root -> val, tmp); // descend for the right subtree
        tmp.pop_back(); // pop the node out from stack if such node has been done(i.e. finished visiting left subtree and right subtree)
    }
};