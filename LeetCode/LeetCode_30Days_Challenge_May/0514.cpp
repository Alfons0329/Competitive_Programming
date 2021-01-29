#define N 26
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = create_node();
        root_bk = root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        root = root_bk;
        for(char c : word){
            int offset = c - 'a'; // offset
            if(root->child[offset] == NULL){
                node* new_node = create_node();
                root->child[offset] = new_node;
            }
            root = root->child[offset];
        }
        root->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        root = root_bk;
        for(char c : word){
            int offset = c - 'a'; // offset
            if(root->child[offset]){
                root = root->child[offset];
            }
            else{
                return false;
            }
        }
        return root->is_end; // apple match applepie
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        root = root_bk;
        for(char c : prefix){
            int offset = c - 'a'; // offset
            if(root->child[offset]){
                root = root->child[offset];
            }
            else{
                return false;
            }
        }
        return true; // apple match applepie
    }
    
private:
    struct node{
        bool is_end;
        node* child[N];
    };
    
    node* create_node(){
        node* new_node = new node;
        new_node->is_end = false;
        for(int i = 0; i < N; i++){
            new_node->child[i] = NULL;
        }
        return new_node;
    }
    
    node* root;
    node* root_bk;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
