#include <cstdio>
double f[510][510];
bool vis[510][510];
double calc(int n,int m)
{
    if (n==0 && m==1)
        return(1);
    if (n==1 && m==0 || n<0 || m<0)
        return(0);
    if (vis[n][m])
        return(f[n][m]);
    vis[n][m]=true;
    return(f[n][m]=n+m&1?(calc(n-1,m)*n+calc(n,m-1)*m)/(n+m):calc(n,m-1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
    static int id=0;
        printf("Case %d: %.10f\n",++id,calc(n,m));
    }
    return(0);
}

