#include <cstdio>
using namespace std;
int countDivisor(int n)
{
    int div=0;
    for(int i=1;i*i<=n;++i)
        if(n%i==0)
        {
            if(i*i==n)div++;//when n is a square number
            else div+=2;
        }
    return div;
}
int main()
{
    int n;
    while(scanf("%d",&n))
    {
        printf("%d\n",countDivisor(n));
    }
    return 0;
}



