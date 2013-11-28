#include <cstdio>
int a[110];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for (int j=x;j<=y;j++)
            a[j]++;
    }
    bool flag=true;
    for (int i=1;i<=n;i++)
        if (a[i]!=1)
        {
            printf("%d %d\n",i,a[i]);
            flag=false;
            break;
        }
    if (flag)
        printf("OK\n");
    return(0);
}

