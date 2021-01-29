class Solution 
{
    public:
        string lastSubstring(string s) 
        {
            int cand_pos = 0; // position that can be the start of candidate
            int max_pos = 0; // position where max character lies
            int n = s.size();
            int first_find = 0; // if this is the first kind of such substring starting at position i
            int offset = 1; // string offset for lexicographical comparison
            char max_char = 0;

            for(int i = 0; i < n; i++)
            {
                if(s[i] > max_char) // if this char is greater than the previous, use this
                {
                    max_char = s[i]; // update max character
                    max_pos = i; // update max pos
                    first_find = 1; // the string starting at this position is currently the first and the only one
                    offset = 1;
                }
                else if(first_find == 0) // compare the candidates
                {
                    if(max_pos + offset < n) // lies in the legal position
                    {
                        if(s[i] > s[max_pos + offset]) // check if another greater char exists
                        {
                            max_pos = i - offset; // if so, update the max position
                            first_find = 1; // give up the old 
                        }
                        else if(s[i] == s[max_pos + offset]) // increment
                        {
                            offset++;
                        }
                        else
                        {
                            first_find = 1; // give up such result if encounter a smaller one and keep the old
                        }
                    }
                }
                else if(s[i] == max_char) // else if this char is equal, which means find the second one (i.e. string startin start with same char) to compare
                {
                    offset = 1; // reset offset
                    first_find = 0; // mark as false for not the first one
                }
            }
            return s.substr(max_pos);
        }    
};
