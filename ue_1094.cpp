#include <cstdio>
int a[1010],b[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,D;
        scanf("%d%d%d",&n,&m,&D);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        bool flag=false;
        static int id=0;
        printf("case %d:\n",++id);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i]+b[j]==D)
                {
                    printf("x[%d]+y[%d]=%d\n",i-1,j-1,D);
                    flag=true;
                }
        if (!flag)
            printf("nothing\n");
    }
    return(0);
}

