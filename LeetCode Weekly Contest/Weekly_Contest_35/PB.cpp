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
    string preString="";
    string tree2str(TreeNode* t)
    {

        if (t==NULL) return "";

        preorderTraverse(t);
        return preString;
    }
    void preorderTraverse(TreeNode* t)
    {
        if((t==NULL))  //if reached a null node, return
            return ;

        preString+=to_string(t->val); //but the node with null L child and null R child is still a valid node, append to ans

        if((t->left==NULL&&t->right==NULL))
            return ; //but once we reach such node with L R child of null node, return

        preString+="("; //else add data
        preorderTraverse(t->left);
        preString+=")";

        if(t->right) //if with right child, traverse it (such as left is null but right is valid)
        {
            preString+="(";
            preorderTraverse(t->right);
            preString+=")";
        }
    }
};
