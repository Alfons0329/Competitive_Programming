#include <bits/stdc++.h>
using namespace std;
vector<vector<char > > country;
int lang_cnt;
void DFS(int row,int col,char target)
{
    if(country[row][col]==target&&country[row][col]!='X')
    {
        country[row][col]='X';
        DFS(row-1,col,target); //n
        DFS(row-1,col+1,target); //ne
        DFS(row,col+1,target); //e
        DFS(row+1,col+1,target); //se
        DFS(row+1,col,target); //s
        DFS(row+1,col-1,target); //sw
        DFS(row,col-1,target); //w
        DFS(row-1,col-1,target); //nw
    }
    //after DFS is done, increment the lang_cnt;
    lang_cnt++;
}
bool cmp(pair<char,int> p1,pair<char,int> p2)
{
    return p1.second>p2.second;
}
int main()
{
    vector<char> onedim;
    int tc,world=1;
    int row,col;
    cin>>tc;
    while(tc--)
    {
        cout<<"hi";

        cin>>row>>col;
        cout<<"hi";
        country.resize(row+1);
        //extend one row and col for better solving DFS

        for(int i=0;i<row+1;i++)
        {
            country[i][0]='X';
        }

        for(int i=0;i<col+1;i++)
        {
            country[0][i]='X';
        }

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col+1;j++)
            {
                char tmp;
                cin>>tmp;
                country[i][j]=tmp;
                onedim.push_back(tmp);
            }
        }

        cout<<"Map is \n";
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                cout<<country[i][j];
            }
            cout<<endl;
        }

        set<char> charset(onedim.begin(),onedim.end()); //for unique element
        set<char>::iterator itr;

        vector<pair<char,int> >anspair;
        anspair.resize(charset.size());
        int cnt=0;
        for(itr=charset.begin();itr!=charset.end();itr++,cnt++)
        {
            lang_cnt=0;
            DFS(1,1,*itr);
            anspair[cnt].first=*itr;
            anspair[cnt].second=lang_cnt;
        }

        sort(anspair.begin(),anspair.end(),cmp);

        printf("World #%d",world);

        for(int i=0;i<anspair.size();i++)
        {
            cout<<anspair[i].first<<": "<<anspair[i].second<<endl;
        }

        charset.clear();
        onedim.clear();
        country.clear();
        anspair.clear();

        world++;

    }
    return 0;
}
