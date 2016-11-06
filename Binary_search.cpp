#include<cstdio>
int main()
{
    int num[11]={0,1,2,3,4,5,6,7,8,9,10},Beg=1,End=10,Mid,Item,Loc;
    scanf("%d",&Item);
    Mid=(int)((Beg+End)/2);
    while(Beg<=End&&Item!=num[Mid])
    {
        if(Item<num[Mid])
        End=Mid-1;
        else
        Beg= Mid+1;
        Mid=(int)((Beg+End)/2);
    }

    if(Item==num[Mid])
    {
        Loc=Mid;
        printf("Found in %d position",Loc);
    }
    else
    {
         Loc=0;
      printf("Not Found");
    }

    return 0;
}
