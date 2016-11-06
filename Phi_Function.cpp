#include<cstdio>
long phi(long n)
{
    long rel=n;
    for(long  i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            rel-=rel/i;
        }
    }
    // this case will happen if n is a prime number
  // in that case we won't find any prime that divides n
  // that's less or equal to sqrt(n)

    if(n>1)rel-=rel/n;
    return rel;
}
int main()
{
    long N;
    while(scanf("%ld",&N))
        printf("%ld\n",phi(N));
    return 0;
}
