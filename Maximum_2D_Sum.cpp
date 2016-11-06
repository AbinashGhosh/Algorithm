#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <iostream>
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
using namespace std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define FOR(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double,double> pdd;
typedef pair<ll , ll > pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll > vl;

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
int m[100][100],temp[100],st,s,e;

int maxSS(int n)
{
    int maxs=0,sum=0;
    st=1,s=0,e=0;
    for(int i=0;i<n;++i)
    {
        sum+=temp[i];
        if(sum<0) sum=0,st=i+1;
        else if(maxs<sum)maxs=sum,s=st,e=i;
    }
    return maxs;
}
int maxsum2D(int r,int c)
{
    int maxs,ans=INT_MIN,L,R,T,B;
    for(int i=0;i<c;++i)
    {
        mem(temp,0);
        for(int j=i;j<c;++j)
        {
            for(int k=0;k<r;++k)
            temp[k]+=m[k][j];
            maxs=maxSS(r);
            if(maxs>ans)
            {
                ans=maxs;
                L=i;
                R=j;
                T=s;
                B=e;
            }
        }
    }
    printf("(%d,%d)-(%d,%d) ",T,L,B,R);
    return ans;
}
int main()
{
    //READ("in.txt");
    int r, c;
    while(scanf("%d %d",&r,&c)==2)
    {
        for(int i=0;i<r;++i)
            for(int j=0;j<c;++j)
               scanf("%d",&m[i][j]);
        int res=maxsum2D(r,c);
        printf(" %d\n",res);
    }
    return 0;
}


