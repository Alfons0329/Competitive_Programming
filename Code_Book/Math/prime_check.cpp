bool is_prime(long long int num)
{
    for(int i = 1; i <= sqrt(num); i++)
    {
        if(num % i == 0)
        {
            return false;
        }
    }
    return true;
}
