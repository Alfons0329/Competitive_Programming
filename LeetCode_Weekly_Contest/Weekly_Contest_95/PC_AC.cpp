/*
Algorithm with inclusion and exclusion along with binary search
*/
class Solution
{
public:
    int nthMagicalNumber(int N, int A, int B)
    {
        unsigned long long int low_bound = min(A, B), up_bound = 1e18;
        unsigned long long int mid = 0, lcm = (A * B) / gcd(A, B);
        while(low_bound < up_bound)
        {
            mid = (low_bound + up_bound) / 2;
            if(mid / A + mid / B - mid / lcm < N) //less than N, increase the lower bound
            {
                low_bound = mid + 1;
            }
            else
            {
                up_bound = mid;
            }
            printf("low %llu mid %llu up %llu\n", low_bound, mid, up_bound);
        }
        return low_bound % (unsigned long long int)(pow(10, 9)+ 7); //
    }
    unsigned long long int gcd(unsigned long long int a, unsigned long long int b)
    {
        // Everything divides 0
        if (a == 0 || b == 0)
        {
            return 0;
        }
        // base case
        if (a == b)
        {
            return a;
        }

        // a is greater
        if (a > b)
        {
            return gcd(a-b, b);
        }
        return gcd(a, b-a);
    }
};
