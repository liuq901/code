#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x1,y1,x2,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        static int id=0;
        printf("Case %d: ",++id);
        if ((x1+y1&1)!=(x2+y2&1))
            printf("impossible\n");
        else
            printf("%d\n",x1+y1==x2+y2 || x1-y1==x2-y2?1:2);
    }
    return(0);
}

