#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
struct edge
{
    int x,y;
    edge(int x,int y):x(x),y(y){}
};
vector <edge> e[20];
vector <int> node[110];
int n,mod,f[110],g[110],c[110][110];
int find(int *f,int x)
{
    if (x!=f[x])
        f[x]=find(f,f[x]);
    return(f[x]);
}
int d[110][110];
void build(const vector <int> &b)
{
    int n=b.size();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            d[i][j]=c[b[i-1]][b[j-1]];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            d[i][j]%=mod;
            if (d[i][j]<0)
                d[i][j]+=mod;
        }
}
int *a[110];
int calc(int n)
{
    for (int i=1;i<=n;i++)
        a[i]=d[i];
    int ans=1;
    for (int i=1;i<=n;i++)
    {
        if (a[i][i]==0)
            for (int j=i+1;j<=n;j++)
                if (a[j][i]!=0)
                {
                    swap(a[i],a[j]);
                    ans*=-1;
                    break;
                }
        if (a[i][i]==0)
            return(0);
        for (int j=i+1;j<=n;j++)
            while (a[j][i])
            {
                swap(a[i],a[j]);
                ans*=-1;
                ll p=a[j][i]/a[i][i];
                for (int k=i;k<=n;k++)
                {
                    a[j][k]=(a[j][k]-a[i][k]*p)%mod;
                    if (a[j][k]<0)
                        a[j][k]+=mod;
                }
            }
    }
    for (int i=1;i<=n;i++)
        ans=ll(ans)*a[i][i]%mod;
    if (ans<0)
        ans+=mod;
    return(ans);
}
int get(int len)
{
    memset(c,0,sizeof(c));
    for (int i=0;i<e[len].size();i++)
    {
        int x=find(f,e[len][i].x),y=find(f,e[len][i].y);
        c[x][x]++;
        c[y][y]++;
        c[x][y]--;
        c[y][x]--;
        x=find(g,x),y=find(g,y);
        if (x!=y)
            g[max(x,y)]=min(x,y);
    }
    for (int i=1;i<=n;i++)
        node[i].clear();
    for (int i=1;i<=n;i++)
        if (find(f,i)==i)
            node[find(g,i)].push_back(i);
    int ret=1%mod;
    for (int i=1;i<=n;i++)
        if (node[i].size()>=2)
        {
            build(node[i]);
            ret=ll(ret)*calc(node[i].size()-1)%mod;
        }
    for (int i=1;i<=n;i++)
        f[i]=find(g,i);
    return(ret);
}
int main()
{
    while (1)
    {
        int m;
        scanf("%d%d%d",&n,&m,&mod);
        if (n==0 && m==0 && mod==0)
            break;
        for (int i=1;i<=10;i++)
            e[i].clear();
        for (int i=1;i<=m;i++)
        {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[z].push_back(edge(x,y));
        }
        for (int i=1;i<=n;i++)
            f[i]=g[i]=i;
        int ans=1%mod;
        for (int i=1;i<=10;i++)
            ans=ll(ans)*get(i)%mod;
        for (int i=1;i<=n;i++)
            if (f[i]!=1)
                ans=0;
        printf("%d\n",ans);
    }
    return(0);
}

