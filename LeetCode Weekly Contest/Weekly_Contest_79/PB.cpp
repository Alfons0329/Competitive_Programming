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
    TreeNode* pruneTree(TreeNode* root)
    {
        if(pruneit(root)) //last one for root
        {
            root = NULL;
        }
        return root;
    }
    bool pruneit(TreeNode* cur) //1 for need prune
    {
        if(cur == NULL)
        {
            cout<<"Case 1 "<<endl;
            return 0;
        }
        cout<<"Traverse to "<<cur->val<<endl;

        if(cur->left == NULL && cur->right == NULL && cur->val == 0)
        {
            cout<<"Case 2 "<<endl;
            return 1;
        }

        if(cur->left == NULL && cur->right  && pruneit(cur->right) && cur->val == 0)
        {
            cout<<"Case 3 "<<endl;
            return 1;
        }

        if(cur->left && cur->right == NULL && pruneit(cur->left) && cur->val == 0)
        {
            cout<<"Case 4 "<<endl;
            return 1;
        }

        if(cur->left == NULL && cur->right == NULL && cur->val == 1)
        {
            cout<<"Case 5 "<<endl;
            return 0;
        }

        /*if(pruneit(cur->left) && pruneit(cur->right)) //if both subtree all contains 0 remove such node
        {
            cout<<"Case 4 "<<endl;
            cur->left = NULL;
            cur->right = NULL;
            //return 1;
        }*/
        bool left_check = pruneit(cur->left);
        bool right_check = pruneit(cur->right);

        if(left_check) //if left subtree needs to be pruned
        {
            cout<<"Case 6 "<<endl;
            cur->left = NULL;
            // return 1;
        }
        if(right_check) //if right subtree needs to be pruned
        {
            cout<<"Case 7 "<<endl;
            cur->right = NULL;
            // return 1;
        }

        return left_check & right_check & (cur->val == 0); //subtree only delete for this one
        /*
        if(cur->left && cur->left->val == 1)
        {
            return 0;
        }
        if(cur->left && cur->left->val == 0)
        {
            return 1;
        }


        if(cur->right && cur->right->val == 0)
        {
            return 0;
        }
        if(cur->right && cur->right->val == 1)
        {
            return 1;
        }*/

    }
};
