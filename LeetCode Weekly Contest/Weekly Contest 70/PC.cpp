/*
############################################ UNSOLVED!!! ###################################################
*/
class Solution {
public:
    bool can = false;
    bool canTransform(string start, string end)
    {
        if(start == end)
            return 1;
        else if(start.size() != end.size())
        {
            return 0;
        }

        int len = start.size();
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < len && ptr2 < len) //both in the boundary
        {
            while(ptr1 < len && start[ptr1] == 'X') //iterate till not X in start
                ptr1++;

            while(ptr2 < len && end[ptr2] == 'X') //iterate till not X in end
                ptr2++;

            if(start[ptr1] != end[ptr2]) //example  XL RX they are different, unable to swap
                return 0;

            //iterate till next non X, both increment

            if(start[ptr1] == 'R' && ptr1 > ptr2) //R of start is right to the R of end,
            //R can only move right but this situation needs R to move left, which is a contradiction
            {
                return 0;
            }
            else if(start[ptr1] == 'L' && ptr2 > ptr1)
            //L of start is left to the L of end,
            //L can only move left but this situation needs L to move right, which is a contradiction
            {
                return 0;
            }
            ptr1++;
            ptr2++;

        }
        return 1;
    }

};
