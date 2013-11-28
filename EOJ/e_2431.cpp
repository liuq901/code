#include <cstdio>
typedef long long ll;
ll c[20][20];
int main()
{
    for (int i=0;i<=12;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        ll ans=1;
        for (int i=1;i<=m;i++)
        {
            int x;
            scanf("%d",&x);
            ans*=c[n][x];
            n-=x;
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

