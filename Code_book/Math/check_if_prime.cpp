bool is_prime(long long int num)
{
    for(int i=0;i<sqrt(num);i++)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
