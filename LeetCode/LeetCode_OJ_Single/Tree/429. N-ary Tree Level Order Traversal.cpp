/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root){
            return{};
        }
        
        vector<vector<int> > res;
        queue<Node*> q;
        q.push(root);
        res.push_back({root -> val});
        
        while(q.size()){
            vector<int> res_cur_level;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* cur_node = q.front();
                q.pop();
                for(Node* child : cur_node -> children){
                    q.push(child);
                    res_cur_level.push_back(child -> val);
                }
            }
            if(res_cur_level.size()){
                res.push_back(res_cur_level);
            }
        }
        
        return res;
    }
};