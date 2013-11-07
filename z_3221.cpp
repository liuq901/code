#include <cstdio>
const int N=1010;
int dep,hp[N],X[N],Y[N],a[N][N],b[N][N];
bool vis[N];
inline int sqr(int x)
{
    return(x*x);
}
inline int dist(int u,int v)
{
    return(sqr(X[u]-X[v])+sqr(Y[u]-Y[v]));
}
int q[N],d[N];
int bfs(int n)
{
    int l,r;
    q[l=r=1]=1;
    d[1]=0;
    vis[1]=true;
    if (a[1][n]==dep)
        return(1);
    while (l<=r)
    {
        int x=q[l++];
        for (int i=1;i<=b[x][0];i++)
        {
            int y=b[x][i];
            if (vis[y])
                continue;
            vis[y]=true;
            d[y]=d[x]+1;
            if (a[y][n]==dep)
                return(y);
            q[++r]=y;
        }
    }
    return(-1);
}
int get(int hp,int D)
{
    if (hp<=0)
        return(0);
    return(hp/D+(hp%D!=0));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,R,K,D;
        scanf("%d%d%d%d",&n,&R,&K,&D);
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&X[i],&Y[i],&hp[i]);
            b[i][0]=0;
            vis[i]=false;
        }
        dep++;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                if (dist(i,j)<=sqr(R))
                {
                    a[i][j]=dep;
                    b[i][++b[i][0]]=j;
                    b[j][++b[j][0]]=i;
                }
       int k=bfs(n);
       if (k==-1 || k!=-1 && d[k]>=K)
           printf("NO\n\n");
       else
       {
           K-=d[k]+1;
           hp[k]-=D;
           hp[n]-=D;
           int t=0;
           for (int i=2;i<n;i++)
               if (a[i][n]==dep)
                   t+=get(hp[i],D);
           if (t>K/2)
               t=K/2;
           if (t>=get(hp[n],D))
               printf("YES\n\n");
           else
               printf("NO\n\n");
       }
    }
    return(0);
}

