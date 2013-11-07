#include <cstdio>
#include <cstring>
#include <cmath>
const double eps=1e-8;
int n,tot,b[110],X[110],Y[110],a[1010][3];
double ans,cost[1010];
inline void add(int x,int y)
{
    a[++tot][0]=y,a[tot][1]=1,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
inline double sqr(double x)
{
    return(x*x);
}
inline double dist(int a,int b)
{
    return(sqrt(double(sqr(X[a]-X[b])+sqr(Y[a]-Y[b]))));
}
int pre[110],p[110],q[1000000];
bool in[110];
double d[110];
bool loop(int P)
{
    for (int i=P;;)
    {
        i=pre[i];
        if (i==0)
            return(false);
        if (i==P)
            break;
    }
    for (int i=P;;)
    {
        int x=p[i];
        ans+=cost[x];
        a[x][1]--;
        a[x^1][1]++;
        i=pre[i];
        if (i==P)
            break;
    }
    return(true);
}
bool spfa()
{
    int l=1,r=n;
    for (int i=1;i<=n;i++)
    {
        pre[i]=0;
        d[i]=0;
        q[i]=i;
        in[i]=true;
    }
    while (l<=r)
    {
        int x=q[l++];
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+cost[i]>d[y]+eps)
            {
                d[y]=d[x]+cost[i];
                pre[y]=x;
                p[y]=i;
                if (loop(y))
                    return(true);
                if (!in[y])
                {
                    in[y]=true;
                    q[++r]=y;
                }
            }
        }
    }
    return(false);
}
int main()
{
    int A,B;
    while (scanf("%d%d%d",&n,&A,&B)==3)
    {
        tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&X[i],&Y[i]);
            while (1)
            {
                int x;
                scanf("%d",&x);
                if (x==0)
                    break;
                add(i,x);
            }
        }
        for (int i=1;i<=n;i++)
            for (int j=b[i];j;j=a[j][2])
            {
                int y=a[j][0];
                cost[j]=dist(i,y)*A-B;
                if (a[j][1]==0)
                    cost[j]*=-1;
            }
        ans=0;
        while (spfa());
        static int id=0;
        printf("Case %d: %.2f\n",++id,ans);
    }
    return(0);
}

