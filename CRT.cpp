//Abinash Ghosh(Om)
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define Sort(x) sort(x.begin(),x.end())
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef  long long ll;
typedef  pair <int, int> pii;
typedef  pair <double , double> pdd;
typedef  pair <ll , ll > pll;
typedef  vector <int> vi;
typedef  vector <pii> vpii;
typedef  vector <ll > vl;


//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};
//int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};
//int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction


/*
Chinese Remainder Theorem:
Suppose,
X =r1(mod m1)
X =r2(mod m2)
X =r3(mod m3)
.
.
X =rn(mod mn)
If you know r[1..n] and m[1..n] this theorem gives you the value of X.
Theorem Statement:
X=p1*r1*x1 + p2*r2*x2 + p3*r3*x3 +.....+ pn*rn*xn ---(1)
where p(i)= M/m(i)
      M=m1*m2*m3*...mn
Here x(i) is Mulplicative Moduler Inverse of p(i) which modulo by m(i)
Suppose we want to do (d/e)%f
So we don't divide d by e ,but can multiply by g which is MMI of e
respect to modulo by f , means (d*g)%f
e=p[i]
g=x[i]
f=m[i]
Now , pi*xi ~= 1 (mod mi)
      pi*xi -1 = y*mi
      pi*xi - y*mi = 1
Using Extended Euclid Algorithm we can get xi
Then using statement (1) we can get X , that's one of the solution infinity solutions
We can get many solution from X = X ± i*M
*/
int ss;
pii extEuclid(int a,int b)
{
    if(b==0) return pii(1,0);
    else
    {
        pii d=extEuclid(b,a%b);
        return pii(d.y,d.x-d.y*(a/b));
    }
}
int CRT(int m[],int r[],int n)
{
    int M=1,p[n+1];
    FOR(i,0,n-1)
       M*=m[i];
    FOR(i,0,n-1)
       p[i]=M/m[i];
    int X=0;
    FOR(i,0,n-1)
    {
        pii res=extEuclid(p[i],m[i]);
        X+=(res.x*r[i]*p[i]);
    }
    ss=M;
    return X;
}
int main()
{
    //READ("inA.txt");
    //WRITE("outA.txt");
    int m[102],r[102];
    int n;
    scanf("%d",&n);
    FOR(i,0,n-1)
    {
        scanf("%d%d",&r[i],&m[i]);
    }
    int ans= CRT(m,r,n);
    pr(ans);
    FOR(i,1,1000)
    {
        if(ans+i*ss>0){pr(ans+i*ss);break;}
    }
    int i=abs(ans)/ss +1;
    ans=ans+(i*ss);
    printf("%d\n",ans);
    return 0;
}


