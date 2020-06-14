class Solution 
{
    public:
        int choose_l, choose_r, choose_p;
        bool btreeGameWinningMove(TreeNode* root, int n, int x) 
        {
            count_node_subtree(root, x, n);
            return max(max(choose_l, choose_r), choose_p) > n / 2;

        }

        int count_node_subtree(TreeNode* root, int x, int total_n)
        {
            if(root == NULL)
            {
                return 0;

            }
            int left_sub = count_node_subtree(root -> left, x, total_n);
            int right_sub = count_node_subtree(root -> right, x, total_n);

            if(root -> val == x)
            {
                choose_l = left_sub;
                choose_r = right_sub;
                choose_p = total_n - choose_l - choose_r - 1;

            }
            return left_sub + right_sub + 1;

        }

};
