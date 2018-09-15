class LogSystem {
public:
    LogSystem()
    {

    }
    vector<long long int>yr,mn,day,hr,min,sec;
    vector<int>yrres,mnres,dayres,hrres,minres,secres;
    void put(int id, string timestamp)
    {
        /*yr.clear();
        mn..clear();
        day.clear();
        hr.clear();
        min.clear();
        sec.clear();*/

        yr.push_back(stoll(timestamp.substr(0,4)));
        mn.push_back(stoll(timestamp.substr(0,4)+timestamp.substr(5,2)));
        day.push_back(stoll(timestamp.substr(0,4)+timestamp.substr(5,2)+timestamp.substr(8,2)));
        hr.push_back(stoll(timestamp.substr(0,4)+timestamp.substr(5,2)+timestamp.substr(8,2)+timestamp.substr(11,2)));
        min.push_back(stoll(timestamp.substr(0,4)+timestamp.substr(5,2)+timestamp.substr(8,2)+timestamp.substr(11,2)+timestamp.substr(14,2)));
        sec.push_back(stoll(timestamp.substr(0,4)+timestamp.substr(5,2)+timestamp.substr(8,2)+timestamp.substr(11,2)+timestamp.substr(14,2)+timestamp.substr(17,2)));
    }

    vector<int> retrieve(string s, string e, string gra)
    {
        vector<int> nullVector={};
        yrres.clear();
        mnres.clear();
        dayres.clear();
        hrres.clear();
        minres.clear();
        secres.clear();
        if(gra=="Year")
        {
            string st=s.substr(0,4);
            string ed=e.substr(0,4);
            for(int i=0;i<yr.size();i++)
            {
                if(yr[i]<=stoll(ed)&&yr[i]>=stoll(st))
                {
                    yrres.push_back(i+1);
                }
            }
            return yrres;
        }
        else if(gra=="Month")
        {
            string st=s.substr(0,4)+s.substr(5,2);
            string ed=e.substr(0,4)+e.substr(5,2);
            for(int i=0;i<mn.size();i++)
            {
                if(mn[i]<=stoll(ed)&&mn[i]>=stoll(st))
                {
                    mnres.push_back(i+1);
                }
            }
            return mnres;
        }
        else if(gra=="Day")
        {
            string st=s.substr(0,4)+s.substr(5,2)+s.substr(8,2);
            string ed=e.substr(0,4)+e.substr(5,2)+e.substr(8,2);
            for(int i=0;i<day.size();i++)
            {
                if(day[i]<=stoll(ed)&&day[i]>=stoll(st))
                {
                    dayres.push_back(i+1);
                }
            }
            return dayres;
        }
        else if(gra=="Hour")
        {
            string st=s.substr(0,4)+s.substr(5,2)+s.substr(8,2)+s.substr(11,2);
            string ed=e.substr(0,4)+e.substr(5,2)+e.substr(8,2)+e.substr(11,2);
            for(int i=0;i<hr.size();i++)
            {
                if(hr[i]<=stoll(ed)&&hr[i]>=stoll(st))
                {
                    hrres.push_back(i+1);
                }

            }

            return hrres;
        }
        else if(gra=="Minute")
        {
            string st=s.substr(0,4)+s.substr(5,2)+s.substr(8,2)+s.substr(11,2)+s.substr(14,2);
            string ed=e.substr(0,4)+e.substr(5,2)+e.substr(8,2)+e.substr(11,2)+e.substr(14,2);
            for(int i=0;i<min.size();i++)
            {
                if(min[i]<=stoll(ed)&&min[i]>=stoll(st))
                {
                    minres.push_back(i+1);
                }
            }
            return minres;
        }
        else if(gra=="Second")
        {
            string st=s.substr(0,4)+s.substr(5,2)+s.substr(8,2)+s.substr(11,2)+s.substr(14,2)+s.substr(17,2);
            string ed=e.substr(0,4)+e.substr(5,2)+e.substr(8,2)+e.substr(11,2)+e.substr(14,2)+e.substr(17,2);
            for(int i=0;i<sec.size();i++)
            {
                if(sec[i]<=stoll(ed)&&sec[i]>=stoll(st))
                {
                    secres.push_back(i+1);
                }
                //cout<<"i is now "<<i<<" sec is now "<<sec[i]<<"Start is "<<stoll(st)<<" end is "<<stoll(ed)<<endl;
            }
            return secres;
        }
        return nullVector; //default for compilation
    }
};
