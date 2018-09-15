#define MAXN 1010000
#define LL long long
#define ll __int64
#define INF 0xfffffff
#define mem(x) memset(x,0,sizeof(x))
#define PI acos(-1)
#define eps 1e-8
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
    int maxc;
    int longestUnivaluePath(TreeNode* cur)
    {
        maxc=0;
        dfs(cur);
        return maxc;
    }
    int dfs(TreeNode* cur)
    {
        if(cur==NULL)
            return 0;

        int lunival=dfs(cur->left),runival=dfs(cur->right),tmp=0;
        //cout<<"Now at "<<cur->val<<"maxc   "<<maxc<<"lni"<<lunival<<" runi  "<<runival<<endl;
        if((cur->left && cur->val==cur->left->val)&&(cur->right && cur->val==cur->right->val)) //both the same ,connect together
            maxc=max(maxc,lunival+runival+2);//both connection
        if(cur->left && cur->val==cur->left->val)
            tmp=max(tmp,lunival+1);
        if(cur->right && cur->val==cur->right->val)
            tmp=max(tmp,runival+1);
        maxc=max(maxc,tmp);//update ans,compare the connected version or only one side
        /*since    1
                /    \
              1      1
                      \
                      2
                        \
                        2
                        \
                         2
                         \
                          2
        although the connected seems better, but the right tmp after return from recursion
        */
        return tmp;//return current univalue path
    }
};
