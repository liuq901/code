#include <cstdio>
const int N=100010;
int q[N],b[N],a[N][2];
void bfs()
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            q[++r]=y;
        }
    }
}
int n,B,f[N],s[N];
void update(int ma,int sum,int &f,int &s)
{
    if (ma==0)
        f=s=1;
    else if (sum+1<=B)
        f=ma,s=sum+1;
    else
        f=ma+1,s=1;
}
void dp()
{
    for (int _=n;_;_--)
    {
        int x=q[_],ma=0,sum=0;
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (f[y]>ma)
                ma=f[y],sum=s[y];
            else if (f[y]==ma)
                sum+=s[y];
        }
        update(ma,sum,f[x],s[x]);
    }
}
int ans[N],F[N],S[N];
void getans()
{
    for (int _=1;_<=n;_++)
    {
        int x=q[_],ma=F[x],sum=S[x];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (f[y]>ma)
                ma=f[y],sum=s[y];
            else if (f[y]==ma)
                sum+=s[y];
        }
        int size;
        update(ma,sum,ans[x],size);
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0],&tmp1=F[y],&tmp2=S[y];
            if (f[y]<ma)
                tmp1=ans[x],tmp2=size;
            else if (f[y]==ma && s[y]<sum)
                update(ma,sum-s[y],tmp1,tmp2);
            else
            {
                int tma=F[x],tsum=S[x];
                for (int j=b[x];j;j=a[j][1])
                {
                    int z=a[j][0];
                    if (y==z)
                        continue;
                    if (f[z]>tma)
                        tma=f[z],tsum=s[z];
                    else if (f[z]==tma)
                        tsum+=s[z];
                }
                update(tma,tsum,tmp1,tmp2);
            }
        }
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&B);
        if (n==0 && B==0)
            break;
        for (int i=1;i<=n;i++)
            b[i]=0;
        for (int i=2;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            a[i][0]=i,a[i][1]=b[x],b[x]=i;
        }
        bfs();
        dp();
        getans();
        static int id=0;
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
            printf("%d\n",ans[i]);
    }
    return(0);
}

