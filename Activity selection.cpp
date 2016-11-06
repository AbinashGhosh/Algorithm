#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
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
using  namespace  std;

#define PI acos(-1.0)
#define MAX 10000007
#define EPS 1e-9

#define mem(a,b) memset(a,b,sizeof(a))
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

//int dx[]={1,0,-1,0};
//int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1, 0, 1};
//int dy[]={0,1,1, 1, 0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1, 1, 2};
//int dy[]={1,2, 2, 1,-1,-2,-2,-1};//Knight Direction

/*
*/
pii work[200];
bool cmp(pii a,pii b)
{
    ///if end time equal work with earlier start time
    if(a.y==b.y)return a.x<b.x;
    return a.y<b.y;///sort by end time
}
int ActivSelection(int n)
{
    int prev_endtime=-1,ans=0;
    sort(work,work+n);
    for(int i=0;i<n;i++)
    {
        if(work[i].x>prev_endtime)
        {
            ans++;
            prev_endtime=work[i].y;
        }
    }
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");
    int n,ans;
    scanf("%d",&n);            ///number of work
    /// Start time and End Time
    for(int i=0;i<n;i++)
        scanf("%d%d",&work[i].x,&work[i].y);
    ans=ActivSelection(n);
    printf("%d\n",ans);
    return 0;
}

