#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int a[10],b[10],sum[65540][2];
pair <int,int> same[10][100];
bool init()
{
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int h1,m1,h2,m2;
        char p1,p2,c1,c2;
        scanf("%d:%d%c%c=%d:%d%c%c",&h1,&m1,&p1,&c1,&h2,&m2,&p2,&c2);
        if (p1==p2)
        {
            if (c1!=c2 || h1!=h2 || m1!=m2)
                return(false);
            continue;
        }
        if (p1=='B' && p2=='A')
        {
            swap(h1,h2);
            swap(m1,m2);
            swap(c1,c2);
        }
        if (m1!=m2)
            return(false);
        int u=c1-'A'+1,v=c2-'A'+1;
        pair <int,int> tmp=make_pair(v,h2);
        if (same[u][h1].first!=0 && same[u][h1]!=tmp)
            return(false);
        if (h1>=a[u] || h2>=b[v])
            return(false);
        same[u][h1]=tmp;
    }
    return(true);
}
int f[65540][20],pre[65540][20][3];
bool check(int i,int si,int j,int sj)
{
    for (int k=0;si+k<a[i] && sj+k<b[j];k++)
        if (same[i][si+k].first!=0 && same[i][si+k]!=make_pair(j,sj+k))
            return(false);
    return(true);
}
void update(int x0,int y0,int x1,int y1,int z)
{
    f[x0][y0]=min(2,f[x0][y0]+f[x1][y1]);
    pre[x0][y0][0]=x1;
    pre[x0][y0][1]=y1;
    pre[x0][y0][2]=z;
}
vector <int> ansa,ansb;
void print(int n,int m)
{
    if (n==0)
        return;
    print(pre[n][m][0],pre[n][m][1]);
    if (pre[n][m][2]>0)
        ansa.push_back(pre[n][m][2]);
    else
        ansb.push_back(-pre[n][m][2]);
}
void dp(int n,int m,int limit)
{
    for (int i=1;i<=n;i++)
    {
        f[1<<i-1][i]=1;
        pre[1<<i-1][i][2]=i;
    }
    int K=max(n,m);
    for (int i=0;i<=limit;i++)
        for (int j=1;j<=K;j++)
        {
            if (f[i][j]==0)
                continue;
            int sa=sum[i][0],sb=sum[i][1];
            if (sa>sb)
            {
                int delta=sa-sb;
                for (int k=1;k<=m;k++)
                {
                    if (i>>k+n-1&1 || !check(j,a[j]-delta,k,0))
                        continue;
                    int state=i|1<<k+n-1;
                    if (sa>sb+b[k])
                        update(state,j,i,j,-k);
                    else
                        update(state,k,i,j,-k);
                }
            }
            else
            {
                int delta=sb-sa;
                for (int k=1;k<=n;k++)
                {
                    if (i>>k-1&1 || !check(k,0,j,b[j]-delta))
                        continue;
                    int state=i|1<<k-1;
                    if (sa+a[k]>sb)
                        update(state,k,i,j,k);
                    else
                        update(state,j,i,j,k);
                }
            }
        }
    int ans=0,pos=-1;
    for (int i=1;i<=m;i++)
        if (f[limit][i]!=0)
        {
            ans+=f[limit][i];
            pos=i;
        }
    if (ans==0)
        printf("Inconsistent\n");
    else if (ans==1)
    {
        print(limit,pos);
        printf("Alde system:");
        for (int i=0;i<ansa.size();i++)
            printf(" %d",ansa[i]);
        printf("\n");
        printf("Baran system:");
        for (int i=0;i<ansb.size();i++)
            printf(" %d",ansb[i]);
        printf("\n");
    }
    else
        printf("Ambiguous\n");
}
int main()
{
    freopen("ampm.in","r",stdin);
    freopen("ampm.out","w",stdout);
    int n;
    scanf("%*d%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int m;
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    int limit=(1<<n+m)-1;
    for (int i=0;i<=limit;i++)
    {
        for (int j=1;j<=n;j++)
            if (i>>j-1&1)
                sum[i][0]+=a[j];
        for (int j=1;j<=m;j++)
            if (i>>j+n-1&1)
                sum[i][1]+=b[j];
    }
    if (!init())
        printf("Inconsistent\n");
    else
        dp(n,m,limit);
    return(0);
}

