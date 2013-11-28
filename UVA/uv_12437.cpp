#include <cstdio>
#include <cstring>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair <int,int> > S;
int Index,k,sum,vis[10010],ans[10010],c[10010],K[10010],b[10010],dep[10010],a[20010][2];
void dfs(int x)
{
    vis[x]=Index;
    sum++;
    if (dep[x]>dep[k])
        k=x;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (vis[y]!=Index)
        {
            dep[y]=dep[x]+1;
            dfs(y);
        }
    }
}
pair <int,int> work(int x)
{
    Index++;
    dep[x]=1;
    k=0;
    dfs(x);
    Index++;
    dep[k]=1;
    sum=0;
    dfs(k);
    return(make_pair(sum,dep[k]));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(vis,0,sizeof(vis));
        Index=0;
        S.clear();
        for (int i=1;i<=n;i++)
        {
            if (vis[i])
                continue;
            S.push_back(work(i));
        }
        sort(S.begin(),S.end());
        reverse(S.begin(),S.end());
        int Q;
        scanf("%d",&Q);
        for (int i=1;i<=Q;i++)
        {
            scanf("%d",&K[i]);
            c[i]=K[i];
        }
        sort(c+1,c+Q+1);
        reverse(c+1,c+Q+1);
        int t=0,now=0;
        for (int i=1;i<=Q;i++)
        {
            int x=c[i];
            while (t<S.size() && S[t].first>=x)
            {
                now=max(now,S[t].second);
                t++;
            }
            if (t==0)
                ans[x]=-1;
            else if (x<=now)
                ans[x]=x-1;
            else
                ans[x]=now-1+2*(x-now);
        }
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=Q;i++)
            if (ans[K[i]]==-1)
                printf("impossible\n");
            else
                printf("%d\n",ans[K[i]]);
    }
    return(0);
}

