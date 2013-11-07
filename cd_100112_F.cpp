#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
int inf,n,r,anss,nowodd,needview,fa[20],component[20],dist[20][20];
map <int,int> M;
map <int,int>::iterator iter;
int getfa(int x)
{
    if (x==fa[x])
        return(x);
    return(fa[x]=getfa(fa[x]));
}
int dfs(int visit,int odd)
{
    if (visit==needview && odd==0)
        return(0);
    iter=M.find(visit<<n|odd);
    if (iter!=M.end())
        return(iter->second);
    int ans=inf;
    for (int i=0;i<n;i++)
        if (visit&1<<i && odd&1<<i)
            for (int j=i+1;j<n;j++)
                if (visit&1<<j && odd&1<<j && dist[i][j]!=inf)
                    ans=min(ans,dist[i][j]+dfs(visit,odd^1<<i^1<<j));
    for (int i=0;i<n;i++)
        if (visit&1<<i)
            for (int j=0;j<n;j++)
                if (~visit&1<<j && needview&1<<j && dist[i][j]!=inf)
                    ans=min(ans,dist[i][j]+dfs(visit|component[j],odd^1<<i^1<<j));
    M[visit<<n|odd]=ans;
    return(ans);
}
int main()
{
    scanf("%d%d",&n,&r);
    needview=1;
    memset(dist,63,sizeof(dist));
    inf=dist[0][0];
    for (int i=0;i<n;i++)
        fa[i]=i,component[i]=1<<i;
    for (int i=0;i<r;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        if (dist[a][b]>c)
            dist[a][b]=dist[b][a]=c;
        needview|=1<<a|1<<b;
        nowodd^=1<<a^1<<b;
        anss+=c;
        a=getfa(a),b=getfa(b);
        if (a!=b)
        {
            component[a]|=component[b];
            fa[b]=a;
        }
    }
    int d;
    scanf("%d",&d);
    for (int i=0;i<d;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        if (dist[a][b]>c)
            dist[a][b]=dist[b][a]=c;
    }
    for (int i=0;i<n;i++)
        component[i]=component[getfa(i)];
    for (int k=0;k<n;k++)
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    printf("%d\n",anss+dfs(component[0],nowodd));
    return(0);
}

