#include <cstdio>
typedef long long ll;
int c[40][40];
int main()
{
    for (int i=0;i<=30;i++)
    {
        c[i][0]=c[i][i]=1;
        for (int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    ll ans=0;
    for (int i=4;i<=n;i++)
    {
        int p=t-i;
        if (p<1)
            break;
        if (p>m)
            continue;
        ans+=ll(c[n][i])*c[m][p];
    }
    printf("%I64d\n",ans);
    return(0);
}

