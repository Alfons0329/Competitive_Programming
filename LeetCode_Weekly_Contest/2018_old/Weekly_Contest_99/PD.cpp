#define MAXN 10001
/* RE
["FreqStack","push","push","push","push","push","push","push","push","push","push","pop","pop","pop","pop","pop","pop","pop","pop","pop","pop"]
[[],[1],[0],[0],[1],[5],[4],[1],[5],[1],[6],[],[],[],[],[],[],[],[],[],[]]
*/
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
        // printf("x in map [%d] ", num_freq[x]);
        if (++num_freq[x] > maxfreq)
        {
            maxfreq = num_freq[x];
            maxfreq_trace.push(maxfreq);
        }
        freq_pos[num_freq[x]].push(cur_pos);
        freq_stack[cur_pos] = x;
        // printf("pushval [%d] cur_pos = [%d], maxfreq = [%d] ",x , cur_pos, maxfreq);
        // print_stack(freq_pos[num_freq[x]]);

        cur_pos++;
    }

    int pop()
    {
        // printf("trace stk: ");
        // print_stack(maxfreq_trace);
        int pop_pos = freq_pos[maxfreq].top();
        int res = freq_stack[pop_pos];
        freq_pos[maxfreq].pop();
        if (freq_pos[maxfreq].size() == 0)
        {
            // printf("Last maxfreq got no size!! freq [%d] is used out!", maxfreq);
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
        // printf("pop value [%d], maxfreq [%d],\n", res, maxfreq_trace.size(), maxfreq);
        num_freq[res]--; //pop that value
        return res;
    }
    void print_stack(stack<int> in)
    {
        printf("stack: [");
        while (in.size())
        {
            printf("%d, ", in.top());
            in.pop();
        }
        printf("]\n");
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
