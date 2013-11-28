#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=200010;
int n,m,top,idx,tot,dep[N],b[N],dfn[N],low[N],Stack[N],mark[N],lq[N][4],e[1000010][2],a[2000010][2];
void tarjan()
{
    low[1]=dfn[1]=++idx;
    Stack[++top]=1;
    int now;
    lq[now=1][0]=1,lq[now][1]=-1,lq[now][2]=b[1],lq[now][3]=0;
    while (now>0)
    {
        int x=lq[now][0],pre=lq[now][1],i=lq[now][2];
        if (i==0)
        {
            if (dfn[x]==low[x])
            {
                ++tot;
                while (1)
                {
                    int cur=Stack[top--];
                    mark[cur]=tot;
                    if (cur==x)
                        break;
                }
            }
            now--;
            continue;
        }
        if (pre!=-1 && (i+m==pre || pre+m==i))
        {
            lq[now][2]=a[i][1];
            continue;
        }
        int y=a[i][0];
        if (!lq[now][3])
        {
            if (!dfn[y])
            {
                lq[now][3]=1;
                low[y]=dfn[y]=++idx;
                Stack[++top]=y;
                lq[++now][0]=y,lq[now][1]=i,lq[now][2]=b[y],lq[now][3]=0;
                continue;
            }
            else
            {
                low[x]=min(low[x],dfn[y]);
                lq[now][2]=a[i][1];
                continue;
            }
        }
        else
        {
            low[x]=min(low[x],low[y]);
            lq[now][2]=a[i][1];
            lq[now][3]=0;
            continue;
        }
    }
}
int q[N];
void bfs(int S)
{
    int l,r;
    memset(dep,-1,sizeof(dep));
    dep[S]=0;
    q[l=r=1]=S;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (dep[y]==-1)
            {
                dep[y]=dep[x]+1;
                q[++r]=y;
            }
        }
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[i][0]=x,e[i][1]=y;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        memset(dfn,0,sizeof(dfn));
        top=idx=tot=0;
        tarjan();
        memset(b,0,sizeof(b));
        for (int i=1;i<=m;i++)
        {
            int x=mark[e[i][0]],y=mark[e[i][1]];
            if (x==y)
                continue;
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        bfs(1);
        int k=1;
        for (int i=1;i<=tot;i++)
            if (dep[i]>dep[k])
                k=i;
        bfs(k);
        int ans=0;
        for (int i=1;i<=tot;i++)
            ans=max(ans,dep[i]);
        printf("%d\n",tot-ans-1);
    }
    return(0);
}

