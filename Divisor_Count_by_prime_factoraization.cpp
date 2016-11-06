#include<cstdio>
long int divisor_count(long int  n)
{
    long int divisor=1,pow;
    for(long int i=2;i*i<=n;i=(i==2?3:i+2))
    {
        if(n%i==0)
        {
            pow=0;
            while(n%i==0)
            {
                pow++;
                n/=i;
            }
            divisor*=(pow+1);
        }
    }
    printf("%ld ",n);
    if(n!=1)divisor*=2;//if we've still not removed all factors from n,then there is one prime factor left.
    return divisor;
}
int  main()
{
    long int N;
    while(scanf("%ld",&N))
    printf("%ld\n",divisor_count(N));
    return 0;
}
