class LRUCache {
public:
    LRUCache(int capacity) {
        max_cap = capacity;
    }
    
    int get(int key) {
        // check if key exists in the mapping structure
        auto found = m.find(key);
        if(found == m.end()){
            return -1;
        }
        // update the list (LRU cache) in O(1) time with splice
        // head[other element | get key]tail --> [get key | other element]
        cache.splice(cache.begin(), cache, m[key]);
        
        return m[key] -> second;
    }
    
    void put(int key, int value) {
        // printf("put key %d value %d \n", key, value);
        auto found = m.find(key);
        // update the existing element and move it to the front
        if(found != m.end()){
            found -> second -> second = value;
            cache.splice(cache.begin(), cache, found -> second);
        }
        else{
            // remove the least used if capacity of LRU cache is full
            if(cache.size() == max_cap){
                int to_delete = cache.back().first;
                m.erase(m.find(to_delete));
                cache.pop_back();
            }
            // insert at the front of the list
            cache.emplace_front(key, value);
            m[key] = cache.begin();
        }
    }
    
private:
    int max_cap;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> cache;
};