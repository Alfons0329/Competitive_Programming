class Solution {
public:

    static bool decrease(int i,int j)
    {
        return (i>j);
    }
    int leastInterval(vector<char>& tasks, int cool_interval)
    {
        sort(tasks.begin(),tasks.end());
        int sizeall=tasks.size();
        if(tasks.size()==1)
            return 1;
        else if(cool_interval==0)
            return tasks.size();

        int cnt=0,diff=0;
        vector<int> stat (26,0);
        for(int i=0;i<tasks.size();i++)
        {
            stat[tasks[i]-'A']++;
        }
        sort(stat.begin(),stat.end(),decrease);
        //vector<int>res(100*tasks.size(),0); //generate an enough big vector (not mem efficient...)
        //assign the most happened tasks first and used the rest tasks to fill the blank
        cout<<"stat ";
        for(int i=0;i<26;i++)
        {
            cout<<stat[i]<<" ";
        }
        int interval_applied=0,interval_sum=cool_interval*(stat[0]-1),ans=0;
        ans+=stat[0];
        for(int i=1;stat[i]!=0;i++)
        {
            ans+=stat[0]-1;
            stat[i]-=(stat[0]-1);
            if(stat[i]<=0)
                stat[i]=0;
            //stat[i]-=interval_sum;

            interval_applied+=stat[0]-1;
            cout<<"Interval app "<<interval_applied<<endl;
        }
        for(int i=1;i<stat.size();i++)
        {
            if(stat[i]>0)
                ans+=stat[i];
        }
        return max((ans+interval_sum-interval_applied),sizeall);
    }

};
