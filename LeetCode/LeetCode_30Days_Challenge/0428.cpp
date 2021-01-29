class FirstUnique {
public:
    unordered_map<int, int> no;
    unordered_map<int, list<int>::iterator> nl;
    list<int> l;
    
    FirstUnique(vector<int>& nums) {
        for(int x : nums){
            add(x);
        }
    }
    
    int showFirstUnique() {
        return l.size() == 0 ? -1 : l.front();
    }
    
    void add(int value) {
        no[value]++;
        // duplicated
        if(no[value] > 1){
            if(nl.count(value) && l.size()){
                auto it = nl[value];
                l.erase(it);
                nl.erase(value);
            }
        }
        else{
            l.emplace_back(value);
            nl[value] = (--l.end());
        }
        
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
