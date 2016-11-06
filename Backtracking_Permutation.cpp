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
#define int64 long long
#define mem(a,b) memset(a,b,sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define pb push_back
#define READ(f) freopen(f, "r", stdin)
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction

using namespace std;
char arr[]={'a','b','c','d','e'};
vector<char>result;
int taken[20]={0};
void call(int n)
{
    if(result.size()==n)
    {
        for(int i=0;i<n;i++)
        printf("%c",result[i]);
        puts("");
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(taken[i]==0)
        {
            taken[i]=1; result.push_back(arr[i]);
            call(n);
            taken[i]=0; result.pop_back();
        }
    }
}
int main()
{
    call(5);
        return 0;
}
