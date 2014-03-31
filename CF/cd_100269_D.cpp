#include <cstdio>
#include <queue>
using namespace std;
int d[10010],b[10010],a[200010][3];
bool vis[10010];
int main()
{
    freopen("dwarf.in","r",stdin);
    freopen("dwarf.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&d[i]);
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&z,&x,&y);
        a[i][0]=y,a[i][1]=z,a[i][2]=b[x],b[x]=i;
        a[i+m][0]=x,a[i+m][1]=z,a[i+m][2]=b[y],b[y]=i+m;
    }
    priority_queue <pair <int,int> > Q;
    for (int i=1;i<=n;i++)
        Q.push(make_pair(-d[i],i));
    while (!Q.empty())
    {
        int x=Q.top().second;
        Q.pop();
        if (vis[x])
            continue;
        vis[x]=true;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0],z=a[i][1];
            if (d[x]+d[y]<d[z])
            {
                d[z]=d[x]+d[y];
                Q.push(make_pair(-d[z],z));
            }
        }
    }
    printf("%d\n",d[1]);
    return(0);
}

