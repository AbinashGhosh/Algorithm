#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<cctype>
using namespace std;
int main()
{
    int i=0,j,A,B,P;
    char ch[30];
    stack<int>S;
    while(ch[i]!='\0')
    {

        if(isdigit(ch[i]))
        {
            P=ch[i]-'0';
            S.push(P);
        }
        else
        {
            A=S.top();
            S.pop();
            B=S.top();
            S.pop();
            if(ch[i]=='+')
            j=B+A;
            else if(ch[i]=='-')
            j=B-A;
            else if(ch[i]=='*')
            j=B*A;
            else if(ch[i]=='/')
            j=B/A;
            else if(ch[i]=='^')
            j=pow(B,A);
            S.push(j);
        }
        i++;
    }
    printf("%d",S.top());
    return 0;
}
