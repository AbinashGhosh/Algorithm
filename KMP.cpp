#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define READ(f) freopen(f, "r", stdin)
/*
KMP String Matching Algo: Is string P[0..m] in string T[0..n]
as substring or not ? If found we can get the starting index k
where P[0..m]=T[k..k+m-1].If found multiple times, no problem.

Failer/Prefix Function: This function genarate an array next[]
where value of next[i] define length of longest proper sufix of
string P[0...i] which is also prefix of that, means, if next[i]=k
in string P[0...i] , P[0...k-1]=P[i-k+1...i]. Complexity O(m)

Matcher Function: From this function we can know,is string P[0..m]
in string T[0..n] as substring or not using the next[] array.If
string P[0..m] found in string T[0..n] multiple time , we have to
store the starting index only. Complexity O(n)

Total Complexity O(m+n)
*/

//Failer/Prefix Function
void CPF(string P,int next[])
{
    int q=0,m=P.size();
    next[0]=0;
    for(int i=1;i<m;++i){
        while(q>0&&P[i]!=P[q])
           q=next[q-1];
        if(P[i]==P[q])q++;
        next[i]=q;
    }
}
int KMPm(string T,string P)
{
    int q=0,m=P.size(),n=T.size();
    int next[m];
    CPF(P,next);
    for(int i=0;i<n;++i){
        while(q>0&&T[i]!=P[q])
           q=next[q-1];
        if(T[i]==P[q])q++;
        if(q==m)
        {
            q=next[q-1];
        ///store in a array if needed found multiple times
             printf("%d",i-m+1);
             /// return i-m+1;
        }

    }
    return -1;
}
int main()
{
    //READ("in.txt");
    string T,P;
    cin>>T>>P;
    int  ans=KMPm(T,P);
    if(ans==-1) printf("Pattern Not Found\n");
    else printf("Pattern Found At Index %d\n",ans);

    return 0;
}



