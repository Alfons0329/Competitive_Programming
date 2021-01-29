#define MAXN 10001
class FreqStack
{
  public:
    unordered_map<int, int> num_freq;        //mapping num -> freq
    unordered_map<int, stack<int>> freq_pos; //mapping freq -> corresponding positions, ex: freq 4 corresponding to a[3], a[7], a[10]
    stack<int> maxfreq_trace;                //trace max frequency history
    int cur_pos, maxfreq;
    int freq_stack[MAXN]; //data structure
    FreqStack()
    {
        memset(freq_stack, -1, sizeof(freq_stack));
        cur_pos = 0;
        maxfreq = 0;
    }

    void push(int x)
    {
        if (++num_freq[x] > maxfreq)
        {
            maxfreq = num_freq[x];
            maxfreq_trace.push(maxfreq);
        }

        freq_pos[num_freq[x]].push(cur_pos);
        freq_stack[cur_pos] = x;
        cur_pos++;
    }

    int pop()
    {
        int pop_pos = freq_pos[maxfreq].top();
        int res = freq_stack[pop_pos];
        freq_pos[maxfreq].pop();

        if (freq_pos[maxfreq].size() == 0)
        {
            
            if (maxfreq_trace.size() > 1)
            {
                maxfreq_trace.pop();
                maxfreq = maxfreq_trace.top();
            }
            else
            {
                maxfreq = maxfreq_trace.top();
                maxfreq_trace.pop();
            }
        }
        
        num_freq[res]--; //pop that value

        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
