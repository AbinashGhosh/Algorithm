#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <list>
#include <set>
#include <utility>
#include <sstream>
#include<iomanip>

#define PI acos(-1.0)
#define MAX 10000007
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define mp make_pair
#define Sort(x) sort(x.begin(),x.end())
#define Reverse(x) reverse(x.begin(),x.end())
#define REP(i, b, e) for(int i = b; i <= e; i++)
#define pr(x) cout<<x<<"\n"
#define READ(f) freopen(f, "r", stdin)

using namespace std;
int x[30],coun;
bool Place(int k,int i)
{
    for(int j=1;j<k;++j)
        if(x[j]==i||(abs(x[j]-i)==abs(j-k)))
           return false;
    return true;
}
void NQueens(int k,int n)
{
    for(int i=1;i<=n;++i)
    {
        if(Place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                for(int j=1;j<=n;++j)
                printf("%d ",x[j]);
               puts("");
                coun++;
            }
            else NQueens(k+1,n);
        }
    }
}
int main()
{
    //READ("in.txt");
    int n;
    int k;
    REP(k,1,16)
    {
        coun=0;
        scanf("%d",&n);
        NQueens(1,n);
        printf("%d\n",coun);
    }


    return 0;
}

