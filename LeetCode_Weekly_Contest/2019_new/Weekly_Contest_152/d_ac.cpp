class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) 
    {
        vector<int> freq(1 << 26, 0);

        for (string &word : words) 
        {
            int mask = 0;

            for (char c : word)
            {
                mask |= 1 << (c - 'a');
            }

            freq[mask]++;
        }

        vector<int> answer;
        for (string &puzzle : puzzles) 
        {
            int mask = 0;

            for (char c : puzzle)
            {
                mask |= 1 << (c - 'a');
            }

            int first = puzzle[0] - 'a';
            int sub = mask;
            int total = 0;

            while(1) 
            {
                if (sub >> first & 1)
                {
                    total += freq[sub];
                }

                if (sub == 0)
                {
                    break;
                }
                sub = (sub - 1) & mask;
            }
            answer.push_back(total);
        }

        return answer;
    }
};
