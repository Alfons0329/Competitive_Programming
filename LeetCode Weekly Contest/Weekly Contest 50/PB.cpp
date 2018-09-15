class MapSum {
public:
    /** Initialize your data structure here. */
    vector<pair<string,int>> mapp; //initialize a vector of pair here as map
    MapSum()
    {

    }

    void insert(string key, int val)
    {
        pair<string,int> ins;
        int find=0;

        for(int i=0;i<mapp.size();i++)
        {
            if(mapp[i].first==key) //if such key has been inserted before
            {
                mapp[i].second=val; //make that value to be overwritten by the key
                find=1; //which means we find the duplicate
            }
        }
        if(!find) //if no duplicated value before , then insert with the new value
        {
            ins=make_pair(key,val);
            mapp.push_back(ins);
        }
    }

    int sum(string prefix)
    {
        int summation=0;
        for(int i=0;i<mapp.size();i++)
        {
            size_t found=(mapp[i].first).find(prefix); //find such prefix if exist at the "first position"
            if(found!=std::string::npos&&(!found)) //prefix has been found
            {
                summation+=mapp[i].second; //add value and return later
            }
        }
        return summation;
    }
};
