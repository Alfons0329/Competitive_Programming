class Solution
{
public:
    int lenLongestFibSubseq(vector<int>& arr)
    {
        int fir = arr[0], sec = arr[1], thr_expected = 0, res = 0, cur_len;
        set<int> myset(arr.begin(), arr.end());
        for(int i = 0; i < arr.size() - 2; i++)
        {

            for(int j = i + 1; j < arr.size() - 1; j++)
            {
                if(arr[i] + arr[j] >= arr[j + 1])
                {
                    fir = arr[i];
                    sec = arr[j];
                    thr_expected = arr[i] + arr[j];
                    cur_len = 2;
                    for(int k = j + 1; k < arr.size(); k++)
                    {
                        // printf("k [%d] val [%d] ", k ,arr[k]);
                        if(thr_expected == arr[k])
                        {
                            // printf("fir [%d], sec[%d], thr_expected[%d] cur_len [%d] ", fir, sec, thr_expected, cur_len);
                            fir = sec;
                            sec = thr_expected;
                            thr_expected = fir + sec;
                            cur_len++;
                            res = max(cur_len, res);
                            // printf(" res now [%d]\n", res);
                        }
                    }
                }
            }
        }
        return res == 2 ? 0 : res;
    }
};
