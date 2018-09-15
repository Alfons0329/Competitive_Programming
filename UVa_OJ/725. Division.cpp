#include <bits/stdc++.h>
using namespace std;
bool checkunique(int num,int num2)
{
    vector<bool> digit(10,0);
    for(int i=5;i>=1;i--)
    {
        digit[(num%(int)pow(10,i))/(int)pow(10,i-1)]=1;
        digit[(num2%(int)pow(10,i))/(int)pow(10,i-1)]=1;
    }
    int cnt=0;
    for(int i=0;i<10;i++)
    {
        if(digit[i])
            cnt++;
    }

    return (cnt==10)?1:0;

}
void eval(int tmp)
{
    vector<int> solution;
    vector<int> solution2;
    for(int i=10;;i++)
    {
        int tmp2=tmp;
        tmp2*=i;
        if(tmp2>=100000)
        {
            break;
        }
        if(checkunique(tmp2,i))
        {
            solution.push_back(i);
            solution2.push_back(tmp2);
        }
    }
    if(solution.size())
    {
        sort(solution.begin(),solution.end());
        sort(solution2.begin(),solution2.end());
        for(int i=0;i<solution.size();i++)
        {
            printf("%05d / %05d = %d\n",solution2[i],solution[i],tmp);
        }
    }
    else
    {
        printf("There are no solutions for %d.\n",tmp);
    }
}

int main()
{
    int tmp,flag=0;
    while(cin>>tmp)
    {
        if(!tmp)
            break;
        else
        {
            if(flag)
                cout<<endl;

            flag=1;
            eval(tmp);
        }

    }
    return 0;
}
