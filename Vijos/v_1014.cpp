#include <cstdio>
#include <cmath>
#include <utility>
#include <algorithm>
using namespace std;
double f[1010][1010],d[1010][1010];
pair <int,int> a[1010];
inline double sqr(double x)
{
    return(x*x);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            d[i][j]=d[j][i]=sqrt(sqr(a[i].first-a[j].first)+sqr(a[i].second-a[j].second));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            f[i][j]=1e26;
    f[1][1]=0;
    for (int i=1;i<n;i++)
        for (int j=1;j<n;j++)
        {
            int p=max(i,j)+1;
            f[i][p]=min(f[i][p],f[i][j]+d[j][p]);
            f[p][j]=min(f[p][j],f[i][j]+d[i][p]);
        }
    double ans=1e26;
    for (int i=1;i<=n;i++)
        ans=min(ans,min(f[i][n],f[n][i])+d[n][i]);
    printf("%.2f\n",ans);
    return(0);
}

