#include <cstdio>
#include <cstring>
int a[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(a,0,sizeof(a));
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%*s%d%d",&x,&y);
            for (int j=x;j<y;j++)
                a[j]++;
        }
        for (int i=0;i<=1000;i++)
            if (a[i]>0)
                printf("%c",a[i]+'A'-1);
        printf("\n");
    }
    return(0);
}

