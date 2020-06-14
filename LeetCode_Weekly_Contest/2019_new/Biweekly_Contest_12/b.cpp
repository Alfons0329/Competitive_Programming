class Leaderboard
{
public:
    vector<int> all;
    Leaderboard()
    {
        all.clear();
        all.resize(10005);
    }

    void addScore(int id, int sc)
    {

        all[id] += sc;
    }

    int top(int K)
    {
        vector<int> tmp = all;
        nth_element(tmp.begin(), tmp.end() - K, tmp.end()); // partial sort - like

        int idx = 10004, res = 0;
        while (K--)
        {
            res += tmp[idx--];
        }
        return res;
    }

    void reset(int id)
    {
        all[id] = 0;
    }
};