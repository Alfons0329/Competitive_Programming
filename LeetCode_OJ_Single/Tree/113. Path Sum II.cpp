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
    vector<vector<int>>res;
    vector<int> tmp;
    string pathstr;
    int cur_sum = 0;
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        descend(root, sum);
        return res;
    }
    bool descend(TreeNode* root, int& target)
    {
        if(root == NULL)
        {
            printf("leaf\n");
            return false;
        }
        cur_sum += root->val;
        tmp.push_back(root->val);
        if(cur_sum == target && is_leaf(root))
        {
            res.push_back(tmp);
            tmp.pop_back();
            printf("ans\n");
            return true;
        }
        else if(cur_sum != target && is_leaf(root))
        {
            cur_sum -= root->val;
            tmp.pop_back();
            printf("fail\n");
            return false;
        }
        bool left_can = descend(root->left, target);
        bool right_can = descend(root->right, target);
        printf("cur_sum = %d, len of vec = %d\n", cur_sum, tmp.size());
        if(!left_can && !right_can)
        {
            cur_sum -= root->val;
            printf("befor\n");
        }
        return left_can | right_can;
    }
    bool is_leaf(TreeNode* root)
    {
        return root->left == NULL && root->right == NULL;
    }
};
