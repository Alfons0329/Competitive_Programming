#define FORI(n) for(int i = 0; i < n; ++ i)
class Solution
{
public:
    string toGoatLatin(string str)
    {
      stringstream ss(str);
      string tmp, tmp2;
      vector<string> vst;
      int cnt = 0;
      while (ss >> tmp)
      {
          vst.push_back(tmp);
          ++cnt;
      }
      FORI(vst.size())
      {
        cout << vst[i] <<endl;
        if(tolower(vst[i][0]) == 'a'
        ||tolower(vst[i][0]) == 'e'
        ||tolower(vst[i][0]) == 'i'
        ||tolower(vst[i][0]) == 'o'
        ||tolower(vst[i][0]) == 'u')
        {

          vst[i] += "ma";
        }
        else
        {
          vst[i] += vst[i][0];
          vst[i] = vst[i].substr(1, vst[i].size() - 1);
          vst[i] += "ma";
        }
      }
      string append = "";
      string res;
      FORI(vst.size())
      {
        append = "";
        for(int j = 0; j <= i; j++)
        {
          append += "a";
        }
        vst[i] += append;
        res += vst[i];
        res += " ";
      }
      res[res.size() - 1] = 0;
      return res;
    }
};
