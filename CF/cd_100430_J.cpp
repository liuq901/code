#include <cstdio>
int a[40];
bool dfs(int dep,int now,int sum)
{
    if (dep==0 && sum==0)
        return(true);
    if (dep==0 || sum==0)
        return(false);
    while (now*now>sum)
        now--;
    if (now*now*dep<sum)
        return(false);
    for (int i=now;i;i--)
    {
        a[dep]=i;
        if (dfs(dep-1,i-1,sum-i*i))
            return(true);
    }
    return(false);
}
int main()
{
    freopen("squary.in","r",stdin);
    freopen("squary.out","w",stdout);
    int m,n,t=0;
    scanf("%d%d",&n,&m);
    for (;t*t<n;t++);
    t--;
    if (dfs(m,t,n*(m-1)))
    {
        printf("YES\n");
        for (int i=1;i<=m;i++)
            printf("%d%c",n-a[i]*a[i],i==m?'\n':' ');
    }
    else
        printf("NO\n");
    return(0);
}

