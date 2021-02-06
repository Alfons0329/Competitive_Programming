#define N 26
class Trie {
public:
    /** Initialize your data structure here. */
    struct node{
        struct node* child[N];
        bool is_end;
    };
    
    node* create(){
        node* new_node = new node;
        new_node->is_end = false;
        for(int i = 0; i < N; i++){
            new_node->child[i] = NULL;
        }
        return new_node;
    }
    
    node* root;
    Trie() {
        // Init a root node;
        root = create();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        node* cur = root;
        for(char c : word){
            if(cur->child[c - 'a'] == NULL){
                cur->child[c - 'a'] = create();
            }
            cur = cur->child[c - 'a'];
        }
        cur->is_end = true; // Mark is_end as true for a termination of a word
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node* cur = root;
        for(char c : word){
            // One character in the word is mismatch, return false
            if(cur->child[c - 'a'] == NULL){
                return false;
            }
            // Else, keep traversing the trie tree
            cur = cur->child[c - 'a'];
        }
        
        // This have to be completely match, so check if the current node has reach to the end (not prefix matching)
        return cur->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node* cur = root;
        int cnt = 0;
         for(char c : prefix){
            // One character in the word is mismatch, return false
            if(cur->child[c - 'a'] == NULL){
                return false;
            }
            // Else, keep traversing the trie tree
            cur = cur->child[c - 'a'];
        }
        
        // Only the prefix has been total match, will be fine
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */