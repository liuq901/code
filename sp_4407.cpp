#include <cstdio>
#include <cstring>
typedef long long ll;
bool a[10][10];
char s[100];
int ans,n;
int find(int x,int *f)
{
    if (x!=f[x])
        f[x]=find(f[x],f);
    return(f[x]);
}
void dfs(int dep,bool root,int *f)
{
    if (dep==n+1)
    {
        ans+=root;
        return;
    }
    for (int i=1;i<=n;i++)
    {
        int g[10];
        for (int j=1;j<=n;j++)
            g[j]=f[j];
        if (!a[i][dep] || find(i,g)==find(dep,g))
            continue;
        g[find(i,g)]=find(dep,g);
        dfs(dep+1,root,g);
    }
    if (!root)
        dfs(dep+1,true,f);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (!n)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            for (int j=1;j<=n;j++)
                a[i][j]=s[j-1]=='1';
        }
        ans=0;
        int f[10];
        for (int i=1;i<=n;i++)
            f[i]=i;
        dfs(1,0,f);
        printf("%d\n",ans);
    }
    return(0);
}

