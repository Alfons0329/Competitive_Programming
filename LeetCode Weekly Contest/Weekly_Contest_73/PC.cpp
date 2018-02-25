class Solution
{
public:
    string customSortString(string sss, string ttt)
    {
        //sss source ttt target string for the targeted customization
        string res="";
        for(int ptr1=0;ptr1<sss.size();ptr1++) //increment
        {
            for(int ptr2=0;ptr2<ttt.size();ptr2++)
            {
                if(sss[ptr1]==ttt[ptr2]) //find the order
                {
                    res+=sss[ptr1];
                    ttt[ptr2]='.'; //mark that as used
                }
            }
        }
        for(int i=0;i<ttt.size();i++)
        {
            if(ttt[i]!='.') //concatenate the rest character (use dot to symbolize it was used for custom sort before)
            {
                res+=ttt[i];
            }
        }
        return res;
    }
};
