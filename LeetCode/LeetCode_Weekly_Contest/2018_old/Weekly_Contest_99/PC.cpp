/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode*> allPossibleFBT(int N)
    {
        printf("N =  %d \n", N);
        TreeNode* root = new TreeNode(0);
        root->left = root->right = NULL;
        vector<TreeNode*> res;
        if(!(N & 1))
        {
            return {};
        }
        else if(N == 1)
        {
            res.push_back(root);
            return res;
        }
        // N--; //minus one, has created the root
        for(int left = 1; left <= N - 1; left += 2) //left subtree node count
        {
            vector<TreeNode*> left_subtree = allPossibleFBT(left);
            vector<TreeNode*> right_subtree = allPossibleFBT(N - left - 1); //minus left subtree and the root
            // printf("left size %d ,  right size %d \n", left_subtree.size(), right_subtree.size());
            for(auto it : left_subtree)
            {
                for(auto it2 : right_subtree) //all conbinations
                {
                    TreeNode* new_node = new TreeNode(0); //connect two subtree with the root
                    new_node->left = it;
                    new_node->right = it2;
                    res.push_back(new_node);
                }
            }
        }

        return res;
    }
};
