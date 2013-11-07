#include <cstdio>
#include <algorithm>
#define N 1000010
using namespace std;
int s[N],q[N],c[N],f[N],d[N],b[N],a[N*2][2];
int main()
{
    int n,m,E,W;
    while (scanf("%d%d%d%d",&n,&m,&E,&W)==4)
    {
        for (int i=1;i<=n;i++)
            b[i]=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+m][0]=x,a[i+m][1]=b[y],b[y]=i+m;
        }
        for (int i=1;i<=n;i++)
            d[i]=0;
        int l,r;
        q[l=r=1]=1;
        d[1]=1;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (d[y]==0)
                {
                    f[y]=x;
                    q[++r]=y;
                    d[y]=d[x]+1;
                }
            }
        }
        for (int i=r;i;i--)
        {
            int x=q[i];
            s[x]=x<=E;
            for (int j=b[x];j;j=a[j][1])
            {
                int y=a[j][0];
                if (d[x]+1==d[y])
                    s[x]+=s[y];
            }
        }
        int rootE,rootW;
        for (int i=1;i<=r;i++)
        {
            int x=q[i];
            if (s[x]==0)
            {
                rootW=x;
                rootE=f[x];
                break;
            }
        }
        for (int i=1;i<=n;i++)
            d[i]=0;
        q[l=r=1]=rootE;
        d[rootE]=1;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (d[y]==0)
                {
                    d[y]=d[x]+1;
                    q[++r]=y;
                }
            }
        }
        int Q;
        scanf("%d",&Q);
        for (int i=1;i<=Q;i++)
        {
            int x;
            scanf("%d",&x);
            c[i]=d[x];
        }
        sort(c+1,c+Q+1);
        for (int i=2;i<=Q;i++)
            c[i]=max(c[i],c[i-1]+1);
        for (int i=1;i<=n;i++)
            d[i]=0;
        q[l=r=1]=rootW;
        d[rootW]=1;
        while (l<=r)
        {
            int x=q[l++];
            for (int i=b[x];i;i=a[i][1])
            {
                int y=a[i][0];
                if (d[y]==0)
                {
                    d[y]=d[x]+1;
                    q[++r]=y;
                }
            }
        }
        int now=n-W+1;
        for (int i=1;i<=W;i++)
            f[i]=d[now++];
        sort(f+1,f+W+1);
        int ans=0;
        for (int i=1;i<=Q;i++)
            ans=max(ans,c[i]+f[Q-i+1]);
        printf("%d\n",ans-1);
    }
    return(0);
}

