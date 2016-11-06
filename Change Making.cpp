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

/*Problem : Change Making
Descripsion: Assume that you have unlimited supply of coin with
different values. I have to make a change value using minimum
number of coin.
Solution: Sort the coin by value and start with the larger valued
coin  which is smaller or equal and subtract the value how much
its possible, then work same with next coin.
*/
int coin[20];
int  ChangeMaking(int n,int change)
{
    int ans=0;
    sort(coin,coin+n);
    for(int i=n-1;i>=0;i--)
    {
        while(change>=coin[i])
        {
            ans++;
            change-=coin[i];
        }
    }
    return ans;
}
int main()
{
    //READ("in.txt");
    //WRITE("out.txt");

    int n,change,ans;

    scanf("%d",&n);            ///number of coin available
    for(int i=0;i<n;i++)
        scanf("%d",&coin[i]);
    scanf("%d",&change);       ///money to make change
    ans=ChangeMaking(n,change);
    printf("%d",ans);
    return 0;
}

