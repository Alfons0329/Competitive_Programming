class Solution
{
public:
    double largestTriangleArea(vector<vector<int>>& points)
    {
        //points = 50, butr force OK
        double a = 0.0f, b = 0.0f,c = 0.0f ,s = 0.0f, area = 0.0f, max_area = 0.0f;
        for(int i = 0; i < points.size() - 2; i++)
        {
            for(int j = i + 1; j < points.size() - 1; j++)
            {
                for(int k = j + 1; k < points.size(); k++)
                {
                    a = dist(points[i],points[j]);
                    b = dist(points[j],points[k]);
                    c = dist(points[i],points[k]);
                    s = (a + b + c) / 2.0f;
                    area = sqrt(s * (s - a) * (s - b) * (s - c));
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
    double dist(vector<int> p1, vector<int> p2)
    {
        return sqrt(abs(p1[0] - p2[0]) * abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]) * abs(p1[1] - p2[1]));
    }

};
