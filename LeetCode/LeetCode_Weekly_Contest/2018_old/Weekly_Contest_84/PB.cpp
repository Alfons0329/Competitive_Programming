#define FORI(n) for(int i = 0; i < n; ++ i)
class mys
{
public:
    mys()
    {
        idx = 0;
        src = "";
        dst = "";
    }
    int idx;
    string src, dst;
};
bool mycmp(mys mys1, mys mys2)
{
    return mys1.idx < mys2.idx;
}
class Solution
{
public:
    string findReplaceString(string str, vector<int>& indexes, vector<string>& sources, vector<string>& targets)
    {
        int f = 0;
        string str2("");
        int j = 0;
        mys tmp;
        tmp.idx = 0;
        tmp.src = " ";
        tmp.dst = " ";
        vector<mys>myst(0, tmp);
        FORI(indexes.size())
        {
            tmp.idx = indexes[i];
            tmp.src = sources[i];
            tmp.dst = targets[i];
            myst.push_back(tmp);
        }
        //sort(myst.begin(), myst.end(), mycmp);
        int n = indexes.size();
        for (int i = 0; i < n; i++)
        {
			for (int j = i + 1; j < n; j++)
				if (myst[i].idx > myst[j].idx)
                {
					swap(myst[i], myst[j]);
				}
		}
        for(int i = 0; i < str.size();)
        {
            f = str.find(myst[j].src);
            // cout << " f and i "<<f<<" , "<<i<<endl;
            if(f != string::npos && f == i)
            {
                str2 += myst[j].dst;
                i += myst[j].src.size();
                // cout << " in 2 "<<"repalce "<<myst[j].src <<" with  "<< myst[j].dst << "str2 now "<<str2 <<endl;
                ++j;
            }
            else
            {
                // cout << " in "<<endl;
                str2 += str[i];
                ++i;
            }
        }
        return str2;
    }
};
