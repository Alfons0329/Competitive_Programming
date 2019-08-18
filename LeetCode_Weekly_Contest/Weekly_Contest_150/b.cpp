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
    
    int maxLevelSum(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        int lv = 1, max_lv = 1, cur_sum = 0, max_sum = INT_MIN;

        while(q.size())
        {
            cur_sum = 0;
            int sz = q.size();

            while(sz--)
            {
                root = q.front();
                q.pop();
                cur_sum += root -> val;
                if(root -> left)
                {
                    q.push(root -> left);
                }
                if(root -> right)
                {
                    q.push(root -> right);
                }
            }
            if(cur_sum > max_sum)
            {
                max_sum = cur_sum;
                max_lv = lv;
            }
            lv++;
        }    
        return max_lv;
    }
};