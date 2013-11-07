#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int s[4010],a[4010],b[4010],c[4010],d[4010],g[4010],p[4010];
ll f[2][4010];
bool pre[4010][4010];
inline bool cmp1(int x,int y)
{
    return(a[x]<a[y]);
}
inline bool cmp2(int x,int y)
{
    return(b[x]<b[y]);
}
void print(int n,int m)
{
    while (n!=0 && m!=0)
    {
        int x=n-1,y=m-pre[n][m];
        if (y==m)
            s[c[n]]=g[c[n]];
        else
            s[c[n]]=p[m];
        n=x,m=y;
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            c[i]=i;
        }
        int m;
        scanf("%d",&m);
        for (int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
            p[i]=i;
        }
        for (int i=1;i<=n;i++)
        {
            d[i]=2147483640;
            for (int j=1;j<=m;j++)
                if (abs(a[i]-b[j])<d[i])
                {
                    d[i]=abs(a[i]-b[j]);
                    g[i]=j;
                }
        }
        sort(c+1,c+n+1,cmp1);
        sort(p+1,p+m+1,cmp2);
        for (int i=0;i<=1;i++)
            for (int j=0;j<=m;j++)
                f[i][j]=1LL<<60;
        f[0][0]=0;
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
            {
                int x=c[i],y=p[j];
                if (f[i-1&1][j-1]+abs(a[x]-b[y])<f[i&1][j])
                {
                    f[i&1][j]=f[i-1&1][j-1]+abs(a[x]-b[y]);
                    pre[i][j]=true;
                }
                if (f[i-1&1][j]+d[x]<f[i&1][j])
                {
                    f[i&1][j]=f[i-1&1][j]+d[x];
                    pre[i][j]=false;
                }
            }
            for (int j=0;j<=m;j++)
                f[i-1&1][j]=1LL<<60;
        }
        cout<<f[n&1][m]<<endl;
        print(n,m);
        for (int i=1;i<=n;i++)
            printf("%d%c",s[i],i==n?'\n':' ');
    }
    return(0);
}

