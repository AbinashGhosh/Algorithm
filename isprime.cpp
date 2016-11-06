#include<cstdio>
using namespace std;

bool isprime(long long n)
{
  if(n <2) return false;
  if(n==2) return true;
  if(n%2==0)return false;
  for (long long i = 3; i * i <= n; i+=2)
    if (n % i == 0) return false;
  return true;
}
int main()
{
    int c=0;
    for(int i=1;i<=1000;i++)
    if(isprime(i))c++;//printf("%d ",i);
    printf("%d ",c);
    return 0;
}
