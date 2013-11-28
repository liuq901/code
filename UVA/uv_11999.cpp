#include <cstdio>
typedef long long ll;
const int maxn=40010;
const ll INF=2000000000000000000LL;
int s[210][210],old[210][210],now[210][210],cnt[maxn],A[maxn],B[maxn],cycle[maxn],belong[maxn],to[maxn][2];
bool vis[210][210];
bool init(int n,int m)
{
    int t=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            old[i][j]=t;
            to[t][0]=i,to[t][1]=j;
            vis[i][j]=false;
            t++;
        }
    t=0;
    for (int i=2;i<=n+m;i++)
        if (i&1)
            for (int j=1;j<=n;j++)
            {
                int k=i-j;
                if (k>=1 && k<=m)
                    now[j][k]=t++;
            }
        else
            for (int j=n;j;j--)
            {
                int k=i-j;
                if (k>=1 && k<=m)
                    now[j][k]=t++;
            }
    int tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (vis[i][j])
                continue;
            int x=i,y=j;
            tot++;
            cycle[tot]=0;
            while (!vis[x][y])
            {
                vis[x][y]=true;
                int tmp=now[x][y];
                x=to[tmp][0];
                y=to[tmp][1];
                cnt[tmp]=cycle[tot];
                cycle[tot]++;
                belong[tmp]=tot;
            }
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int p=s[i][j];
            if (belong[p-1]!=belong[old[i][j]])
                return(false);
            A[p]=cycle[belong[p-1]];
            B[p]=cnt[p-1]-cnt[old[i][j]];
            if (B[p]<0)
                B[p]+=A[p];
        }
    return(true);
}
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if (b==0)
    {
        x=1,y=0;
        return(a);
    }
    ll p,q,ret=gcd(b,a%b,p,q);
    x=q,y=p-a/b*q;
    return(ret);
}
bool flag;
bool calc(ll a1,ll b1,ll a2,ll b2,ll &a,ll &b)
{
    if (flag)
    {
        if (b1%a2!=b2)
            return(false);
        b=b1;
        return(true);
    }
    b2-=b1;
    ll k1,k2,p=gcd(a1,a2,k1,k2);
    if (b2%p!=0)
        return(false);
    k1*=b2/p;
    k2*=b2/p;
    ll delta=a2/p;
    k1%=delta;
    while (k1>0)
        k1-=delta;
    while (k1<0)
        k1+=delta;
    b=b1+a1*k1;
    a=a1/p*a2;
    if (a1/p>INF/a2)
        flag=true;
    return(true);
}
ll work(int n,int m)
{
    flag=false;
    ll a,b;
    if (!calc(A[1],B[1],A[2],B[2],a,b))
        return(-1);
    for (int i=3;i<=n*m;i++)
        if (!calc(a,b,A[i],B[i],a,b))
            return(-1);
    return(b);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&s[i][j]);
        if (n==1 && m==1)
        {
            printf("0\n");
            continue;
        }
        if (!init(n,m))
            printf("-1\n");
        else
            printf("%lld\n",work(n,m));
    }
    return(0);
}

