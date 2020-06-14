class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        map<string, int>mymap;
        map<string, int>mymap2;
        stringstream ss(A);
        stringstream ss2(B);

        vector<string> stra;
        vector<string> strb;
        vector<string> res;
        string tmp;

        while(ss >> tmp)
        {
            stra.push_back(tmp);
        }

        while(ss2 >> tmp)
        {
            strb.push_back(tmp);
        }

        for(int i = 0; i < stra.size(); i++)
        {
            mymap[stra[i]]++;
        }
        for(int i = 0; i < strb.size(); i++)
        {
            mymap2[strb[i]]++;
        }

        for(map<string, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
        {
            if(it->second == 1)
            {
                if(mymap2[it->first] == 0)
                {
                    res.push_back(it->first);
                }
            }
        }

        for(map<string, int>::iterator it = mymap2.begin(); it != mymap2.end(); it++)
        {
            if(it->second == 1)
            {

                if(mymap[it->first] == 0)
                {
                    res.push_back(it->first);
                }
            }
        }
        return res;
    }
};
