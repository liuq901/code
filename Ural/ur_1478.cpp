#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=2000;
struct edge
{
    int x,y,len;
    edge(){}
    edge(int x,int y,int len):x(x),y(y),len(len){}
};
inline bool operator <(const edge &a,const edge &b)
{
    return(a.len<b.len);
}
edge e[N*N];
int X[N],Y[N],b[N],c[N],f[N];
int find(int x)
{
    if (x!=f[x])
        f[x]=find(f[x]);
    return(f[x]);
}
int sqr(int x)
{
    return(x*x);
}
int dist(int u,int v)
{
    return(sqr(X[u]-X[v])+sqr(Y[u]-Y[v]));
}
bool a[N][N];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        int tot=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                e[++tot]=edge(i,j,dist(i,j));
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            a[i][1]=true;
            b[i]=1;
            c[i]=0;
        }
        for (int i=1;i<=2*n;i++)
            f[i]=i;
        sort(e+1,e+tot+1);
        int cnt=n;
        for (int i=1,j;i<=tot;i=j)
        {
            for (j=i;j<=tot && e[i].len==e[j].len;j++)
            {
                int x=find(e[j].x),y=find(e[j].y);
                if (x!=y)
                {
                    f[x]=f[y]=++cnt;
                    b[cnt]=b[x]+b[y];
                    c[cnt]=c[x]+c[y];
                    for (int k=2;k<=b[cnt];k++)
                        for (int l=1;l<=b[x];l++)
                            if (a[x][l] && a[y][k-l])
                            {
                                a[cnt][k]=true;
                                break;
                            }
                }
                c[find(e[j].x)]++;
            }
            for (int j=1;j<=cnt;j++)
                if (b[j]*(b[j]-1)==2*c[j])
                    a[j][1]=true;
        }
        for (int i=1;i<=n;i++)
            printf("%d",a[cnt][i]);
        printf("\n");
    }
    return(0);
}

