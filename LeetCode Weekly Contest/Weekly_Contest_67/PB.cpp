class Solution
{
public:
    const int MAX_CHAR = 26;
    struct Key
    {
        int freq; // store frequency of character
        char ch;

        bool operator<(const Key &k) const
        {
            return freq < k.freq;
        }
    };
    string reorganizeString(string str)
    {
        int n = str.length();

        int count[MAX_CHAR] = {0};
        for (int i = 0 ; i < n ; i++)
            count[str[i]-'a']++;

            priority_queue< Key > pq;
            for (char c = 'a' ; c <= 'z' ; c++)
                if (count[c-'a'])
                    pq.push( Key { count[c-'a'], c} );

        str = "";

        Key prev {-1, '#'} ;
        while (!pq.empty())
        {

            Key k = pq.top();
            pq.pop();
            str = str + k.ch;

            if (prev.freq > 0)
                pq.push(prev);

            (k.freq)--;
            prev = k;
        }
        if(str.size()==n)
        {
            return str;
        }
        else
        {
            return "";
        }
    }
};
