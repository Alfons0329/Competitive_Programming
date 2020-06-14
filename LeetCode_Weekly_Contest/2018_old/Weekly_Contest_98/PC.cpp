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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post)
    {
        return construct(pre, post);
    }
    TreeNode* construct(vector<int>& pre, vector<int>& post)
    {
        if(pre.size() == 1 && post.size() == 1) // the base case with leaf
        {
            //printf("base case presize %d postsize %d\n", pre.size(), post.size());
            TreeNode* newnode = new TreeNode(pre[0]);
            return newnode;
        }
        else if(pre.size() == 0 && post.size() == 0) //the null
        {
            return NULL;
        }

        vector<int> left_subtree_pre;
        vector<int> left_subtree_pos;
        vector<int> right_subtree_pre;
        vector<int> right_subtree_pos;

        int left_subtree_root_pos = 0;

        while(pre[1] != post[left_subtree_root_pos]) //find the equal for the right subtree
        {
            left_subtree_root_pos++;
        }
        // printf("\nleft pos %d with root %d\n", left_subtree_root_pos, pre[0]);

        for(int i = 0; i <= left_subtree_root_pos; i++)//construct the post traverse of left subtree
        {
            left_subtree_pos.push_back(post[i]);
        }
        for(int i = left_subtree_root_pos + 1; i < post.size() - 1; i++)//construct the post traverse of right subtree
        {
            right_subtree_pos.push_back(post[i]);
        }

        for(int i = 1; i <= left_subtree_root_pos + 1; i++)//construct the pre traverse of left subtree
        {
            left_subtree_pre.push_back(pre[i]);
        }
        for(int i = left_subtree_root_pos + 2; i <= post.size() - 1; i++)//construct the pre traverse of right subtree
        {
            right_subtree_pre.push_back(pre[i]);
        }

        //print_subtree_dbg("left pos",left_subtree_pos);
        //print_subtree_dbg("right pos",right_subtree_pos);

        //print_subtree_dbg("left pre",left_subtree_pre);
        //print_subtree_dbg("right pre",right_subtree_pre);

        TreeNode* newnode = new TreeNode(pre[0]); //or post[-1]
        newnode->left = construct(left_subtree_pre, left_subtree_pos);
        newnode->right = construct(right_subtree_pre, right_subtree_pos);
        return newnode;//after construct, return it
    }
    // void print_subtree_dbg(string cond, vector<int>& vec)
    // {
    //     cout << cond << " : " ;
    //     for(int i = 0; i < vec.size(); i++)
    //     {
    //         printf("%d ", vec[i]);
    //     }
    //     printf("\n");
    // }
};
