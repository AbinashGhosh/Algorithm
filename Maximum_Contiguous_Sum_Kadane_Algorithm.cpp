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

int a[1005],s=0,e=0;
//At least one positive number needed for working
int maxSS(int n)
{
    int maxs=0,sum=0;
    for(int i=0;i<n;++i)
    {
        sum=sum+a[i];
        if(sum<0) sum=0,s=i+1;
        else if(maxs<=sum) maxs=sum,e=i;
    }
    return maxs;
}
//Also works for all negative number
int maxSSN(int n)
{
    int maxs=a[0],sum=a[0];
    for(int i=1;i<n;++i)
    {
        sum=max(a[i],sum+a[i]);
        maxs=max(maxs,sum);
    }
    return maxs;
}
int main()
{
    //READ("in.txt");
    int N;
    scanf("%d",&N);
    for(int j=0;j<N;++j)
    scanf("%d",&a[j]);
    int result =maxSS(N);
    printf("%d %d %d\n",result,s,e);

    return 0;
}

