/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d)
    {
        TreeNode* created_root = new TreeNode(0);
        //created_root=root;

        TreeNode* created_left = new TreeNode(0);
        TreeNode* created_right = new TreeNode(0);
        if(d==1) //created at the depth 0 and make the original tree be at left side
        {
            created_root->val=v;
            created_root->left=root;
            created_root->right=NULL;
        }
        else if(d==2) //special case
        {
            created_root=root;
            created_left->val=v;
            created_right->val=v;

            created_left->left=created_root->left;
            created_left->right=NULL;
            created_root->left=created_left;

            created_right->right=created_root->right;
            created_right->left=NULL;
            created_root->right=created_right;
        }
        else if(d>2)
        {
            created_root=root;
            go_and_construct(created_root,v,1,d);
        }

        return created_root;
    }

    void go_and_construct(TreeNode* current,int v,int cur_depth,int target)
    {
        if(cur_depth!=target-1)
        {
            if(current->left)
            {
                go_and_construct(current->left,v,cur_depth+1,target);
            }
            if(current->right)
            {
                go_and_construct(current->right,v,cur_depth+1,target);
            }
        }
        else
        {

            TreeNode* created_left;
            TreeNode* created_right;
            created_left = new TreeNode(0);
            created_right = new TreeNode(0);
            created_left->val=v;
            created_right->val=v;

            created_left->left=current->left;
            created_left->right=NULL;
            current->left=created_left;

            created_right->right=current->right;
            created_right->left=NULL;
            current->right=created_right;
        }

    }

};
