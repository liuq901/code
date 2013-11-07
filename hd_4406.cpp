#include <cstdio>
#include <cstring>
const int N=100;
int S,T,tot,b[N],credit[N],basic[N],a[1000000][3];
double ans,c[1000000];
void add(int x,int y,int z,double p)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],c[tot]=p,b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],c[tot]=-p,b[y]=tot;
}
double GetGPA(int x)
{
    return(x>=60?4-3.0*(100-x)*(100-x)/1600:0);
}
double d[N];
bool in[N];
int pre[N],p[N],q[1000000];
bool SPFA()
{
    for (int i=1;i<=T;i++)
        d[i]=-1e26;
    d[S]=0;
    in[S]=true;
    int l,r;
    q[l=r=1]=S;
    while (l<=r)
    {
        int x=q[l++];
        in[x]=false;
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (a[i][1] && d[x]+c[i]>d[y]+1e-8)
            {
                d[y]=d[x]+c[i];
                pre[y]=x;
                p[y]=i;
                if (!in[y])
                {
                    in[y]=true;
                    q[++r]=y;
                }
            }
        }
    }
    if (d[T]<-1e20)
        return(false);
    for (int i=T;i!=S;i=pre[i])
    {
        int x=p[i];
        a[x][1]--;
        a[x^1][1]++;
    }
    ans+=d[T];
    return(true);
}
int main()
{
    while (1)
    {
        int n,K,m;
        scanf("%d%d%d",&n,&K,&m);
        if (n==0 && K==0 && m==0)
            break;
        for (int i=1;i<=m;i++)
            scanf("%d",&credit[i]);
        for (int i=1;i<=m;i++)
            scanf("%d",&basic[i]);
        S=n+m+1,T=S+1,tot=1;
        memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++)
            add(S,i,K,0);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                int x;
                scanf("%d",&x);
                if (x)
                    add(i,j+n,K,0);
            }
        double Offset=0;
        for (int i=1;i<=m;i++)
            for (int j=basic[i];j<100;j++)
            {
                double now=j<60?10000:0;
                add(i+n,T,1,(GetGPA(j+1)-GetGPA(j))*credit[i]+now);
                Offset+=now;
            }
        ans=-Offset;
        while (SPFA());
        int sum=0;
        for (int i=1;i<=m;i++)
        {
            ans+=GetGPA(basic[i])*credit[i];
            sum+=credit[i];
        }
        if (ans<0)
            ans=0;
        printf("%.6f\n",ans/sum);
    }
    return(0);
}

