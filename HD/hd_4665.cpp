#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,len,a[2010],b[2010],p[2010],cnt[2010],f[2010],g[2010];
bool belong[2010];
bool dfs(int dep)
{
    if (a[min(n,m)]!=b[min(n,m)])
        return(false);
    if (dep==len+1)
    {
        for (int i=1;i<=len;i++)
            printf("%d",belong[i]);
        printf("\n");
        return(true);
    }
    int x=p[dep];
    if (n==m)
    {
        a[++n]=x;
        f[x]++;
        belong[dep]=false;
        if (dfs(dep+1))
            return(true);
        f[x]--;
        n--;
    }
    else
    {
        if (f[x]<cnt[x]/2)
        {
            a[++n]=x;
            f[x]++;
            belong[dep]=false;
            if (dfs(dep+1))
                return(true);
            f[x]--;
            n--;
        }
        if (g[x]<cnt[x]/2)
        {
            b[++m]=x;
            g[x]++;
            belong[dep]=true;
            if (dfs(dep+1))
                return(true);
            g[x]--;
            m--;
        }
    }
    return(false);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&len);
        memset(cnt,0,sizeof(cnt));
        for (int i=1;i<=len;i++)
        {
            scanf("%d",&p[i]);
            cnt[p[i]]++;
        }
        n=m=0;
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        dfs(1);
    }
    return(0);
}

