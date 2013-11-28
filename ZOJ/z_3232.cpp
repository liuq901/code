#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int tot,id,sum,dfn[210],p[210],low[210],d[210],b[210],a[100000][2];
bool in[210],f[210],aa[210][210],ab[210][210];
stack <int> s;
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++id;
    in[x]=true;
    s.push(x);
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (in[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (dfn[x]==low[x])
    {
        p[0]++;
        while (s.top()!=x)
        {
            p[s.top()]=p[0];
            in[s.top()]=false;
            s.pop();
            d[p[0]]++;
        }
        p[x]=p[0];
        in[x]=false;
        s.pop();
        d[p[0]]++;
    }
}
int main()
{
    void add(int,int);
    int n;
    while (scanf("%d",&n)==1)
    {
        memset(b,0,sizeof(b));
        tot=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                scanf("%d",&aa[i][j]);
                if (aa[i][j] && i!=j)
                    add(i,j);
            }
        p[0]=id=0;
        memset(dfn,0,sizeof(dfn));
        memset(d,0,sizeof(d));
        for (int i=1;i<=n;i++)
            if (!dfn[i])
                tarjan(i);
        memset(ab,0,sizeof(ab));
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            {
                int x=p[i],y=p[j];
                if (x!=y && aa[i][j] && !ab[x][y])
                {
                    ab[x][y]=true;
                    add(x,y);
                }
            }
        int ans=0;
        for (int i=1;i<=p[0];i++)
        {
            if (d[i]>1)
                ans+=d[i];
            vector <int> c;
            for (int j=b[i];j;j=a[j][1])
                c.push_back(a[j][0]);
            memset(f,0,sizeof(f));
            for (int j=0;j<c.size();j++)
                for (int k=0;k<c.size();k++)
                    if (j!=k && ab[c[k]][c[j]])
                    {
                        f[j]=true;
                        break;
                    }
            for (int j=0;j<c.size();j++)
                ans+=!f[j];
        }
        printf("%d\n",ans);
    }
    return(0);
}

