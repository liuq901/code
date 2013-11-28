#include <cstdio>
typedef long long ll;
int K,b[50010],a[100010][2],f[50010][510];
ll ans;
void dp(int x,int father)
{
    f[x][0]=1;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (y==father)
            continue;
        dp(y,x);
        for (int j=1;j<=K;j++)
            ans+=ll(f[x][K-j])*f[y][j-1];
        for (int j=1;j<=K;j++)
            f[x][j]+=f[y][j-1];
    }
}
int main()
{
    int n;
    scanf("%d%d",&n,&K);
    for (int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[i][0]=y,a[i][1]=b[x],b[x]=i;
        a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
    }
    dp(1,0);
    printf("%I64d\n",ans);
    return(0);
}

