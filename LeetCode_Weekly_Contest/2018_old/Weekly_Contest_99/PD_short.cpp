#define MAXN 10001
class FreqStack
{
  public:
    unordered_map<int, int> num_freq;        //hash of num to its occurances
    unordered_map<int, stack<int>> freq_stk; //data structure of freq stack, record the occurance of number to certain freq, ex push 2 push 3 push 2 push 4, we have freq[1] = [3, 4](top), freq[2] = [2]
    int maxfreq;
    FreqStack()
    {
        maxfreq = 0;
    }

    void push(int x)
    {
        if (++num_freq[x] > maxfreq)
        {
            maxfreq = num_freq[x];
        }

        freq_stk[num_freq[x]].push(x);
    }

    int pop()
    {
        if (freq_stk[maxfreq].size() == 0)
        {
            maxfreq--; //means all the numbers corresponding to that freq has been used out
        }

        int res = freq_stk[maxfreq].top(); //get the latest element of the same frequency(i.e. last in number)
        freq_stk[maxfreq].pop(); //pop the occurance of that number
        num_freq[res]--; //and then decrease the freq of that number
        
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
