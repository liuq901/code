#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int inf=1<<30;
int tot,S,T,b[210],a[1000000][3];
void add(int x,int y,int z)
{
    a[++tot][0]=y,a[tot][1]=z,a[tot][2]=b[x],b[x]=tot;
    a[++tot][0]=x,a[tot][1]=0,a[tot][2]=b[y],b[y]=tot;
}
int d[210],q[210];
bool build()
{
    int l,r;
    q[l=r=1]=S;
    memset(d,0,sizeof(d));
    d[S]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][2])
        {
            int y=a[i][0];
            if (d[y] || !a[i][1])
                continue;
            d[y]=d[x]+1;
            q[++r]=y;
            if (y==T)
                return(true);
        }
    }
    return(false);
}
int dinic(int x,int flow)
{
    if (x==T)
        return(flow);
    int k=flow;
    for (int i=b[x];i;i=a[i][2])
    {
        int y=a[i][0];
        if (d[y]!=d[x]+1 || !a[i][1])
            continue;
        int t=dinic(y,min(k,a[i][1]));
        k-=t;
        a[i][1]-=t;
        a[i^1][1]+=t;
        if (k==0)
            break;
    }
    if (k==flow)
        d[x]=-1;
    return(flow-k);
}
bool big[110];
int pos[110];
int main()
{
    int TT;
    scanf("%d",&TT);
    while (TT--)
    {
        int n,D;
        scanf("%d%d",&n,&D);
        n+=2;
        for (int i=2;i<n;i++)
        {
            char buf[100];
            scanf("%s",buf);
            big[i]=buf[0]=='B';
            sscanf(buf+2,"%d",&pos[i]);
        }
        big[1]=big[n]=true;
        pos[1]=0,pos[n]=D;
        int l=0,r=D,ans;
        S=1,T=n;
        while (l<=r)
        {
            int mid=l+r>>1;
            memset(b,0,sizeof(b));
            tot=1;
            for (int i=1;i<=n;i++)
                if (big[i])
                    add(i,i+n,inf);
                else
                    add(i,i+n,1);
            for (int i=1;i<=n;i++)
                for (int j=i+1;j<=n;j++)
                    if (pos[j]-pos[i]<=mid)
                        add(i+n,j,inf);
            int sum=0;
            while (build())
            {
                sum+=dinic(S,inf);
                if (sum>=2)
                    break;
            }
            if (sum>=2)
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

