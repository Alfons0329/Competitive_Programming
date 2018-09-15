//617. Merge Two Binary Trees
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2)
    {
        TreeNode* merged_tree_root=NULL; //recursion merging new node for construction or say root
        TreeNode* traverse_ptr1; //traversing down and merging
        TreeNode* traverse_ptr2; //traversing down and merging
        //int check1=0,check2=0;

        merged_tree_root=new TreeNode(0);


        //if current node for merging not null, add value
        if(t1)
        {
            merged_tree_root->val+=t1->val;
        }
        if(t2)
        {
            merged_tree_root->val+=t2->val;
        }

        if(t1==NULL && t2) //null tree merging
        {
            merged_tree_root->left=t2->left;
            merged_tree_root->right=t2->right;
            return merged_tree_root;
        }
        else if(t1&& t2==NULL)
        {
            merged_tree_root->left=t1->left;
            merged_tree_root->right=t1->right;
            return merged_tree_root;
        }
        else if(t1==NULL&&t2==NULL)
            return NULL;
        //recursion merging the left sub tree
        if(t1->left)
        {
            traverse_ptr1=t1->left;
        }
        else
            traverse_ptr1=NULL;

        if(t2->left)
        {
            traverse_ptr2=t2->left;
        }
        else
            traverse_ptr2=NULL;

        merged_tree_root->left=mergeTrees(traverse_ptr1,traverse_ptr2);


        //recursion merging the right sub tree
        if(t1->right)
        {
            traverse_ptr1=t1->right;
        }
        else
            traverse_ptr1=NULL;

        if(t2->right)
        {
            traverse_ptr2=t2->right;
        }
        else
            traverse_ptr2=NULL;

        merged_tree_root->right=mergeTrees(traverse_ptr1,traverse_ptr2);


        return merged_tree_root;
    }
};
