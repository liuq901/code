#include <cstdio>
#include <algorithm>
using namespace std;
struct point
{
    int x,y;
    void in()
    {
        scanf("%d%d",&x,&y);
    }
};
inline bool operator <(const point &a,const point &b)
{
    return(a.x<b.x);
}
int n,K;
point p[100010];
int q[100010],a[100010],s[100010],f[20][100010];
int work()
{
    sort(p+1,p+n+1);
    int m=1;
    a[1]=1;
    for (int i=2;i<=n;i++)
        if (p[i].x==p[i-1].x)
            a[m]++;
        else
            a[++m]=1;
    for (int i=1;i<=m;i++)
        s[i]=s[i-1]+a[i];
    for (int i=0;i<=m;i++)
        f[1][i]=abs(s[i]*K-n);
    for (int i=2;i<=K;i++)
    {
        int l=1,r=0,k=-1,mi=1<<30;
        for (int j=0;j<=m;j++)
        {
            f[i][j]=f[i-1][j]+n;
            while (l<=r && (s[j]-s[q[l]])*K-n>=0)
            {
                f[i][j]=min(f[i][j],f[i-1][q[l]]+(s[j]-s[q[l]])*K-n);
                l++;
            }
            if (l<=r)
                f[i][j]=min(f[i][j],f[i-1][q[l]]+n-(s[j]-s[q[l]])*K);
            while (l<=r && f[i-1][j]+s[j]*K<f[i-1][q[r]]+s[q[r]]*K)
                r--;
            q[++r]=j;
        }
    }
    return(f[K][m]);
}
int gcd(int a,int b)
{
    return(b?gcd(b,a%b):a);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&K);
        if (n==0 && K==0)
            break;
        for (int i=1;i<=n;i++)
            p[i].in();
        int ans=work();
        for (int i=1;i<=n;i++)
            swap(p[i].x,p[i].y);
        ans=min(ans,work());
        int t=gcd(ans,K*K);
        static int id=0;
        printf("%d. %d/%d\n",++id,ans/t,K*K/t);
    }
    return(0);
}

