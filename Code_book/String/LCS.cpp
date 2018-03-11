void LCS(int* xarr, int* yarr, int* carr) //find the length
{
    unsigned int xlen=xarr[0],ylen=yarr[0],LCS_length=0;
    string LCS_string;
    vector<vector<int> > dplist(xlen, vector<int>(ylen));//2d dp array for character matching increase by one for convenience
	for (int i = 0; i < dplist.size(); i++)
		for (int j = 0; j < dplist[i].size(); j++)
			dplist[i][j] = 0;
    //dp traverse
    for (int i = 1; i < xlen/*was increment by 1, so no equal*/; i++)
        for (int j = 1; j < ylen/*was increment by 1, so no equal*/; j++)
        {
            if (xarr[i] == yarr[j]) //since 0 is as size for both
                dplist[i][j] = dplist[i - 1][j - 1] + 1; //increase by one, the encountered pattern
            else
                dplist[i][j] = max(dplist[i][j-1],dplist[i-1][j]);
        }
    getLCS(xarr,yarr,carr,dplist,LCS_string);
    reverse(LCS_string.begin(),LCS_string.end());
    for(int i=0;i<LCS_string.length();i++)
    {
        carr[i] = LCS_string[i];
    }
}
void getLCS(int* xarr, int* yarr, int* carr ,vector<vector <int> >dplist,string& LCS_string)
{
    unsigned int xlen=xarr[0],ylen=yarr[0];
    int current_row=xlen-1,current_col=ylen-1;
    while(dplist[current_row][current_col])
    {
        if(dplist[current_row][current_col]==dplist[current_row-1][current_col])//from up
        {
            current_row--;
        }
        else if(dplist[current_row][current_col]==dplist[current_row][current_col-1])//from left
        {
            current_col--;
        }
        else if(dplist[current_row][current_col]==dplist[current_row-1][current_col-1]+1)//from left up
        {
            LCS_string+=(char)xarr[current_row];
            current_row--;
            current_col--;
        }
    }
}
