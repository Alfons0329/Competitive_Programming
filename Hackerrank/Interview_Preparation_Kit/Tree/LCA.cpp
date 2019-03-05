#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    struct node_data
    {
        int depth;
        Node* parent;
    };
    unordered_map<Node*, node_data> mymap; // hash for child--parent pair
    Node* cur_node;// use for tree traverse
    Node *lca(Node *root, int v1,int v2) 
    {
        Node* res = root;
        Node* p = root;
        Node* q = root;

        mymap[root].depth = 0;
        mymap[root].parent = NULL;

        parent_data(root, 0);

        binary_search(v1, p);
        p = cur_node;
        binary_search(v2, q);
        q = cur_node;

        ascend_LCA(p, q);
        return cur_node;
    }

    void binary_search(int val, Node* root)
    {
        if(val == root -> data)
        {
            cur_node = root;
            return;
        }
        else
        {
            if(val < root -> data)
            {
                binary_search(val, root -> left);
            }
            else if(val > root -> data)
            {
                binary_search(val, root -> right);
            }
        }
    }

    void parent_data(Node* root, int cur_depth)
    {
        if(root != NULL) // if not null, store node <-> node_data to the map
        {
            mymap[root].depth = cur_depth;
        }

        if(root -> left)
        {
            mymap[root -> left].parent = root; //create the child-parent pair for left child
            parent_data(root -> left, cur_depth + 1);
        }

        if(root -> right)
        {
            mymap[root -> right].parent = root; //create the child-parent pair for right child
            parent_data(root -> right, cur_depth + 1);
        }
    }
    void ascend_LCA(Node* p, Node* q)
    {
        if(p == q)
        {
            cur_node = p;
            return;
        }
        if(mymap[p].depth > mymap[q].depth) // if node p is deeper, ascend node p
        {
            ascend_LCA(mymap[p].parent, q);
        }
        else if(mymap[p].depth == mymap[q].depth) // if same depth, ascend both
        {
            ascend_LCA(mymap[p].parent, mymap[q].parent);
        }
        else // otherwise ascend node q
        {
            ascend_LCA(p, mymap[q].parent);
        }
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
  	int v1, v2;
  	std::cin >> v1 >> v2;
  
    Node *ans = myTree.lca(root, v1, v2);
    
  	std::cout << ans->data;

    return 0;
}

