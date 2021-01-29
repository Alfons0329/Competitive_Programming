class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int p) {
        int cnt = 0;
        while(stk.size() && stk.top().first <= p){
            cnt += stk.top().second;
            stk.pop();
            cnt++;
        }
        stk.push({p, cnt});
            
        return cnt + 1;
    }

private:
    stack<pair<int, int>> stk;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
