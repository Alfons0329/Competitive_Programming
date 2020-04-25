#define fi first
#define se second
class LRUCache {
public:
    int max_cap; // max capacity
    unordered_map<int, list<pair<int, int>>::iterator> m; // map key to its correspoonding iterator
    list<pair<int, int>> cache; // the main LRU cache
    
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        // key exist in cache?
        auto f = m.find(key);
        // not exists in cache
        if(f == m.end()){
            return -1;
        }
        // update the current "touched" object to fonr
        cache.splice(cache.begin(), cache, m[key]);
        
        return m[key] -> se;
    }
    
    void put(int key, int value) {
        auto f = m.find(key);
        
        // element exist in cache already, then somply update the value
        if(f != m.end()){
            f -> se -> se = value;
            cache.splice(cache.begin(), cache, f -> se);
        }else{
            // if size reach limit, select LRU and swap out
            if(cache.size() == max_cap){
                int to_delete = cache.back().fi;
                m.erase(m.find(to_delete));
                cache.pop_back();
            }
            
            // insert at the front for newest element (k, v)
            cache.emplace_front(key, value);
            m[key] = cache.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
