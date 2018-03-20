#include <bits/stdc++.h>
using namespace std;
bool check(int m,int tmp)
{
    vector<int> list;
    for(int i = 1; i <= tmp; i++)
        list.push_back(i);

    int c = 0;
    while(list[c] != 13)
    {
        //cout<<list[c]<<" ";
        list.erase(list.begin() + c); //shrink ok
        c += m - 1;
        c=(c>=list.size())?c%list.size():c;
    }
    //cout<<endl;
    return list.size() == 1; //means only 13 left
}
int main()
{
    int tmp;
    while(cin>>tmp)
    {
        if(!tmp)
        {
            break;
        }
        else
        {
            for(int i=1;i<=tmp;i++)
            {
                if(check(i,tmp))
                {
                    cout<<i<<endl;
                    break;
                }
            }

        }
    }
    return 0;
}
