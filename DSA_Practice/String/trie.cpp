#include <bits/stdc++.h>
#define ALPHABET_SIZE 26

using namespace std;

// the trie node struct
struct node{
    struct node* child[ALPHABET_SIZE];
    bool is_end;
};

// create a new node
node* create_node(){
    node* new_node = new node;
    new_node -> is_end = false;
    for(int i = 0; i < ALPHABET_SIZE; i++){
        new_node -> child[i] = NULL;
    }

    return new_node;
}

// insert new node to the trie tree
//
// paremeter:
// root: the starting root
// s: the string data for constructing the trie tree
void insert(node* root, const string& s){
    for(char x : s){
        // if this node has not been inserted before
        if(root -> child[x - 'a'] == NULL){
            // then insert the node at such position
            root -> child[x - 'a'] = create_node();
        }
        // move to the next node
        root = root -> child[x - 'a'];
    }

    // mark as terminate
    root -> is_end = true;
}

// do the string searching, i.e. checking whether the string existing in the already-built trie
//
// parameter:
// root: the starting root
// s: the string data for constructing the trie tree
// retrun found of such string or not
bool search(node* root, const string& s){
    for(char x : s){
        // mismatch
        if(root -> child[x - 'a'] == NULL){
            return false;
        }
        root = root -> child[x - 'a'];
    }

    return root != NULL && root -> is_end;
}

// driver function
int main(){
    // init keys
    int n;
    cout << "# of keys: " << '\n';
    cin >> n;
    vector<string> keys;
    string tmp;
    cout << "enter keys for trie insertion till EOF" << '\n';
    while(n--){
        cin >> tmp;
        keys.push_back(tmp);    
    }

    // insert keys into trie
    node* root = create_node();
    for(auto str : keys){
        insert(root, str);
    }
    cout << "finished constricting trie " << '\n';

    // search query
    cout << "enter keys for trie till EOF" << '\n';
    while(cin >> tmp){
        cout << "search for " << tmp;
        if(search(root, tmp)){
            cout << " found! " << '\n';
        }
        else{
            cout << " not found! " << '\n';
        }
    }
    return 0;
}
