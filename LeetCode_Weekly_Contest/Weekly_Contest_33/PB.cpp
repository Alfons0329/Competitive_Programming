class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
    {
        int d2= dist(p1,p2);
        int d3= dist(p1,p3);
        int d4= dist(p1,p4);
        //1:1:sqrt(2)------>1:1:2 in square
        if(d2==0&&d3==0&&d4==0)
            return false;

        if (d2 == d3 && 2*d2 == d4)
        {
            int d = dist(p2, p4);
            return (d == dist(p3, p4) && d == d2);
        }


        if (d3 == d4 && 2*d3 == d2)
        {
            int d = dist(p2, p3);
            return (d == dist(p2, p4) && d == d3);
        }
        if (d2 == d4 && 2*d2 == d3)
        {
            int d = dist(p2, p3);
            return (d == dist(p3, p4) && d == d2);
        }

        return false;
    }
    int dist(vector<int>& p1,vector<int>& p2)
    {
        return (p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
    }
};
