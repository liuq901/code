#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct edge
{
    int x,y,len;
    edge(){}
    edge(int x,int y,int len):x(x),y(y),len(len){}
};
bool operator <(edge a,edge b)
{
    return(a.len<b.len);
}
edge e[10010];
int X[110],Y[110],f[110],a[110];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        int tot=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                e[++tot]=edge(i,j,abs(X[i]-X[j])+abs(Y[i]-Y[j]));
        sort(e+1,e+tot+1);
        for (int i=1;i<=n;i++)
            f[i]=i;
        int ans=0;
        a[0]=0;
        for (int i=1;i<=tot;i++)
        {
            int x=e[i].x,y=e[i].y;
            if (find(x)==find(y))
                continue;
            ans+=e[i].len;
            f[f[x]]=f[y];
            a[++a[0]]=i;
        }
        bool flag=false;
        for (int i=1;i<=a[0];i++)
        {
            int sum=0;
            for (int j=1;j<=n;j++)
                f[j]=j;
            for (int j=1;j<=tot;j++)
            {
                int x=e[j].x,y=e[j].y;
                if (j==a[i] || find(x)==find(y))
                    continue;
                sum+=e[j].len;
                f[f[x]]=f[y];
            }
            if (sum==ans)
            {
                flag=true;
                break;
            }
        }
        printf("%d\n%s\n",ans,flag?"Yes":"No");
    }
    return(0);
}

