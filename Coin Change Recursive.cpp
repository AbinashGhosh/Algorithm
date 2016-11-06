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

/// Coin Change Call coinC(0,make)
int make,coin[]={1,5,10,25,50},dp[5][100];
int coinC(int i,int amount)
{
    if(i==5)
    {
        if(amount==0) return 1;
        else return 0;
    }
    int r1=0,r2=0;
    if(dp[i][amount]!=-1)return dp[i][amount];
    if(amount-coin[i]>=0)
        r1=coinC(i,amount-coin[i]);
    r2=coinC(i+1,amount);
    return dp[i][amount]=r1+r2;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int T;
    scanf("%d",&T);
    FOR(i,1,T)
    {
        mem(dp,-1);
        scanf("%d",&make);
        int ans=coinC(0,make);
        pr(ans);
    }
    return 0;
}
