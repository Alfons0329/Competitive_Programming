bool issubseq(string str1, string str2, int len1, int len2)
{
    int same_idx = 0;
    for(int i=0;i<len2 && same_idx<len1;i++)
    {
        if(str1[same_idx] == str2[i])
            same_idx++;
    }
    return (same_idx==len1);
}
