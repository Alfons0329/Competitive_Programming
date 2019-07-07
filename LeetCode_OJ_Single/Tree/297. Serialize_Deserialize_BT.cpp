/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
    public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        if(root == NULL)
        {
            return "";
        }
        queue<TreeNode*> q;
        TreeNode* cur;
        string res = "[";
        q.push(root);

        while(q.size())
        {
            cur = q.front();
            if(cur)
            {
                res += (to_string(cur -> val) + ",");
                q.push(cur -> left);
                q.push(cur -> right);
            }
            else
            {
                res += "null,";
            }
            q.pop();
        }

        res.pop_back(); // remove last,
        res += "]";       
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        if(data == "")
        {
            return NULL;
        }

        // parse
        data.pop_back();
        data.erase(data.begin());
        stringstream ss(data);
        string tmp;
        // allocate the parsed data
        vector<string> tree_data;

        while(getline(ss, tmp, ','))
        {
            tree_data.push_back(tmp);
        }

        int n = tree_data.size();
        int root_idx = 1;
        int left_idx = root_idx * 2;
        int right_idx = root_idx * 2 + 1;
        vector<TreeNode*> tree(n + 1, NULL); // padding

        while(right_idx <= n)
        {
            left_idx = root_idx * 2;
            right_idx = root_idx * 2 + 1;
            if(tree_data[root_idx] == "null")
            {
                tree[root_idx] = NULL;
            }
            else
            {
                tree[root_idx] -> val = stoi(tree_data[root_idx]);
                tree[root_idx] -> left = tree[left_idx];
                tree[root_idx] -> right = tree[right_idx];
            }
            root_idx++;
        }
        return tree[1];
    }
};

