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

int coin[101],dp[1001],nc[101];

int coinci(int n,int make)
{
    dp[0]=1;
    FOR(i,0,n-1)
    {
        for(int j=make;j>=coin[i];j--)
        {
            FOR(k,1,nc[i])
            {
                if(j-coin[i]*k>=0)
                    dp[j]+=dp[j-coin[i]*k];
                else break;
            }
        }

    }
    return dp[make];
}
/*
000000
000000
000100
001100
011100
111100

111103
111123
111323
112323
122323
3
*/
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int t,n,make;
    scanf("%d",&t);
    FOR(i,1,t)
    {
        mem(dp,0);
        scanf("%d%d",&n,&make);
        FOR(j,0,n-1)
            scanf("%d",&coin[j]);
        FOR(j,0,n-1)
            scanf("%d",&nc[j]);
        printf("%d\n",coinci(n,make));
    }
    return 0;
}

