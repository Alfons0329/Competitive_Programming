#include <bits/stdc++.h>

using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
};

node* new_node(int new_val)
{
    node* new_node = new node;
    new_node -> val = new_val;
    new_node -> left = new_node -> right = nullptr; 
    return new_node;
}

node* insert(vector<int> input, node* root)
{
    for(int i = 1; i < input.size(); i++)
    {
        int new_val = input[i];
        node* cur = root;
        node* prev = root;
        while(cur)
        {
            prev = cur;
            if(new_val < cur -> val)
            {
                cur = cur -> left;
            }
            else
            {
                cur = cur -> right;
            }
            cout << "prev: " << (char) prev -> val << "cur: " << (char) cur -> val << '\n';
        }

        if(new_val < prev -> val)
        {
            prev -> left = new_node(input[i]);
        }
        else
        {
            prev -> right = new_node(input[i]); 
        }
    }
    return root;
}


int search() 
{

}

int del()
{

}

void specified_traverse(string s, node* root)
{
    for(auto x : s)
    {
        if(root == nullptr) // SIGSEGV prevention
        {
            break;
        }
        if(x == 'L')
        {
            root = root -> left;
        }
        else if(x == 'R')
        {
            root = root -> right;
        }
        else if(x == 'D')
        {
            cout << root -> val << ", ";
        }
    }
}

int main()
{
    int;
    vector<int> input;
    int tmp;
    cout << "Input to build BST, EOF for done " << '\n';
    
    while(cin >> tmp)
    {
        input.push_back(tmp);
    }

    node* root = new node;
    root -> val = input[0];
    root -> left = root -> right = nullptr;
    root = insert(input, root);

    string s;
    cout << "CTF " << endl;
    cin >> s;
    specified_traverse(s, root);

    return 0;
}
