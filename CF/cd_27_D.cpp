#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
int tot,u[110],v[110],dfn[210],low[210],p[210],b[210],a[10000][2];
stack <int> s;
bool f[210];
void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=b[x],b[x]=tot;
}
void tarjan(int x)
{
    dfn[x]=low[x]=++dfn[0];
    s.push(x);
    f[x]=true;
    for (int i=b[x];i;i=a[i][1])
    {
        int y=a[i][0];
        if (!dfn[y])
        {
            tarjan(y);
            low[x]=min(low[x],low[y]);
        }
        else if (f[y])
            low[x]=min(low[x],dfn[y]);
    }
    if (low[x]==dfn[x])
    {
        p[0]++;
        while (s.top()!=x)
        {
            p[s.top()]=p[0];
            f[s.top()]=false;
            s.pop();
        }
        p[x]=p[0],f[x]=false,s.pop();
    }
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        if (u[i]>v[i])
            swap(u[i],v[i]);
    }
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++)
        {
            if (i==j)
                continue;
            if (u[i]<u[j] && u[j]<v[i] && v[i]<v[j])
            {
                add(i,j+m);
                add(j,i+m);
                add(i+m,j);
                add(j+m,i);
            }
        }
    for (int i=1;i<=m*2;i++)
        if (!dfn[i])
            tarjan(i);
    bool flag=true;
    for (int i=1;i<=m;i++)
        if (p[i]==p[i+m])
        {
            flag=false;
            break;
        }
    if (!flag)
        printf("Impossible\n");
    else
    {
        for (int i=1;i<=m;i++)
            printf("%c",p[i]>p[i+m]?'i':'o');
        printf("\n");
    }
    return(0);
}

