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
        node* prev = nullptr;
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

            if(cur && prev)
            {
                // cout << "prev: " << (char) prev -> val << "cur: " << (char) cur -> val << '\n';
            }
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
    node* original = root;
    for(auto x : s)
    {
        if(root == nullptr) // SIGSEGV prevention
        {
            root = original;
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
            cout << (char)root -> val;
        }
    }
}

int main()
{
    int;
    vector<int> input;
    int tmp;
    cout << "Input to build BST, EOF for done " << '\n';

    string s;
    cin >> s;
    for(auto x : s)
    {
        input.push_back(x);
    }

    node* root = new_node(input[0]);
    root = insert(input, root);
    cout << "CTF " << endl;
    cin >> s;
    specified_traverse(s, root);

    return 0;
}
