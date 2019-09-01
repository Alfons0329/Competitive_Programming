class Solution 
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& q) 
    {
        vector<bool> res;
        int n = q.size(), sz = s.size();
        vector<vector<int >> alp(sz + 1, vector<int> (27, 0));
        alp[1][s[0] - 'a']++; 
        for(int i = 1; i < s.size(); i++)
        {
            alp[i + 1] = alp[i];
            alp[i + 1][s[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++)
        {
            int l = q[i][0], r = q[i][1], k = q[i][2];
            int more_odd = 0;
            // check palindrome odd # alphabets
            for(int j = 0; j < 26; j++)
            {
                if((alp[r + 1][j] - alp[l][j]) & 1)
                {
                    more_odd++;
                }
            }
            more_odd--; // central character
            res.push_back(k * 2 >= more_odd);
        }
        return res;
    }
};