#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
int coefficient(int up,int down)
{
    int p=1,q=1;// p/q;
    if(down>up/2)
    {
        down=up-down;
    }
    if(down==0)
        return 1;
    else
    {
        for(int i=0;i<down;i++)
        {
            p=p*(up-i);
            q=q*(i+1);
            //cout<<"p is now"<<p<<" and q is now "<<q<<endl;
        }
    }
    return p/q;
}
int main()
{
    int a;
    cin>>a;
    vector<int>res;
    int b=12345;
    string str1=to_string(b);
    cout<<str1;
    for(int i=0;i<a+1;i++)
    {
        int up=a;
        int down=i;
        //cout<<"up:"<<up<<"down:"<<down<<endl;
        res.push_back(coefficient(up,down));
    }
    cout<<"[";
    for(int i=0;i<res.size()-1;i++)
    {
        cout<<res[i]<<",";

    }
    cout<<res[res.size()-1]<<"]";
	//system("pause");
	return 0;
}
