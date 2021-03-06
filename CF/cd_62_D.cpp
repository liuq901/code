#include <cstdio>
int n,m,ans[2010],b[2010],a[110][110];
bool dfs(int x,int dep,bool flag)
{
    ans[dep]=x;
    if (dep==m)
        return(flag);
    int first=flag?1:b[dep+1];
    for (int i=first;i<=n;i++)
    {
        if (!a[x][i])
            continue;
        a[x][i]--,a[i][x]--;
        if (dfs(i,dep+1,flag || i>b[dep+1]))
            return(true);
        a[x][i]++,a[i][x]++;
    }
    return(false);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<=m;i++)
        scanf("%d",&b[i]);
    for (int i=1;i<=m;i++)
    {
        int x=b[i-1],y=b[i];
        a[x][y]++,a[y][x]++;
    }
    if (dfs(b[0],0,false))
        for (int i=0;i<=m;i++)
            printf("%d%c",ans[i],i==m?'\n':' ');
    else
        printf("No solution\n");
    return(0);
}

