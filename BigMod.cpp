#include<cstdio>
#define ll long long
inline int  bigmod ( int  a, int  p, int  m ) {
    int  res = 1 % m, x = a % m;
    while ( p ) {
        if ( p & 1 ) res = ( res * x ) % m;
        x = ( x * x ) % m; p >>= 1;
    }
    return res;
}
inline ll  bigmod(ll a,ll p,ll m ){
    ll res=1%m,x=a%m;
    while(p){
        if(p&1)res=(res*x)%m;
        x=(x*x)%m;p>>=1;
    }
    return res;
}
int main()
{
    ll ans=(bigmod(2,1024,9)+bigmod(5,1024,9)+1);
    printf("%lld",ans%9);

    return 0;
}
