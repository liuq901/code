#include <cstdio>
const int a[]={0,1,2,3,4,5,6,7,8,9,5,4,3,2,1};
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x>y && x<=5)
            x=15-x;
        printf("%d",a[x]);
        while (a[x]!=y)
        {
            x=(x+1)%15;
            printf(" %d",a[x]);
        }
        printf("\n");
    }
    return(0);
}

