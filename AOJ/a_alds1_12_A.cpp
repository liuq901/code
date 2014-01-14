#include <cstdio>
int cost[110],a[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
        cost[i]=-1;
    }
    cost[1]=0;
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        int k=-1;
        for (int j=1;j<=n;j++)
            if (cost[j]>=0 && (k==-1 || cost[j]<cost[k]))
                k=j;
        ans+=cost[k];
        cost[k]=-2;
        for (int j=1;j<=n;j++)
            if (a[k][j]!=-1 && (cost[j]==-1 || a[k][j]<cost[j]))
                cost[j]=a[k][j];
    }
    printf("%d\n",ans);
    return(0);
}

