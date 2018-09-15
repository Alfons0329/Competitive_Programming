/*
解題思維：利用雜湊列表的方式來進行映射，將檔名先作為key再把相同的檔名映射到同一個位址的哈希表
練習使用map的概念，其實跟vector很像只是改用key作為映射的規矩
it->first;               // same as (*it).first   (the key value)
it->second;              // same as (*it).second  (the mapped value)

URL of this question:
https://leetcode.com/contest/leetcode-weekly-contest-35/problems/find-duplicate-file-in-system/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    unordered_map<string ,vector<string>>fileMapping;
    vector<vector<string>> findDuplicate(vector<string>& paths)
    {
        vector<vector<string>>resultVector;

        for(int i=0;i<paths.size();i++)
        {
            stringTokenizer(paths[i]);
        }
        for(auto it=fileMapping.begin();it!=fileMapping.end();it++) //auto for iterator
        {
            if(it->second.size()>1) //second for the mapped value and first for the key value, if >1 is
                resultVector.push_back(it->second);
            //containing duplicated files
        }
        return resultVector;
    }
    void stringTokenizer(string in)
    {
        string filePath,fileName,fileContent;
        bool path=false,firstFile=false;
        int ptr1,ptr2;
        for(ptr1=0;ptr1<in.length();ptr1++)
        {
            for(ptr2=ptr1+1;ptr2<in.length();ptr2++)
            {
                if(in[ptr2]==' '&&!path)
                {
                    filePath=in.substr(ptr1,ptr2-ptr1);
                    path=true;
                    break;
                }
                else if(in[ptr2]==' ')
                {
                    break;
                }
                else if(in[ptr2]=='(')
                {
                    if(!firstFile)
                    {
                        fileName=in.substr(ptr1,ptr2-ptr1);
                        firstFile=true;
                    }
                    else
                    {
                        fileName=in.substr(ptr1+1,ptr2-ptr1-1);
                    }
                    break;
                }
                else if(in[ptr2]==')')
                {
                    fileContent=in.substr(ptr1,ptr2-ptr1);
                    fileMapping[fileContent].push_back(filePath+"/"+fileName);
                    break;
                }
            }
            ptr1=ptr2;　//the relocation of dual pointer technique
        }
    }

};
int  main(int argc, char const *argv[])
{
    vector<string>inputFileQuery={"root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)", "root 4.txt(efgh)"};
    Solution sol;
    sol.findDuplicate(inputFileQuery);
    return 0;
}
