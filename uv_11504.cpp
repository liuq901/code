#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=100010;
int id,top,tot,c[N],d[N],dfn[N],low[N],b[N],stack[N],a[N][2],e[N][2],tmp[N][3];
bool in[N];
void tarjan(int x)
{
    int now=1;
    tmp[now][0]=x,tmp[now][1]=b[x],tmp[now][2]=0;
    while (now)
    {
        int x=tmp[now][0],i=tmp[now][1];
        if (i==b[x])
        {    
            dfn[x]=low[x]=++id;
            stack[++top]=x;
            in[x]=true;
        }
        if (i!=0)
        {
            tmp[now][1]=a[i][1];
            int y=a[i][0];
            if (!dfn[y])
                tmp[++now][0]=y,tmp[now][1]=b[y],tmp[now][2]=x;
            else if (in[y])
                low[x]=min(low[x],dfn[y]);
        }
        else
        {
            if (dfn[x]==low[x])
            {
                tot++;
                while (stack[top]!=x)
                {
                    int p=stack[top--];
                    in[p]=false;
                    c[p]=tot;
                }
                top--,in[x]=false,c[x]=tot;
            }
            int t=tmp[now--][2];
            low[t]=min(low[t],low[x]);
        }
    }
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
            e[i][0]=x,e[i][1]=y;
        }
        memset(dfn,0,sizeof(dfn));
        id=tot=0;
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        memset(d,0,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int x=e[i][0],y=e[i][1];
            if (c[x]!=c[y])
                d[c[y]]++;
        }
        printf("%d\n",count(d+1,d+tot+1,0));
    }
    return(0);
}

