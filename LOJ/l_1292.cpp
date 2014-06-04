#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
struct point
{
    double x,y;
};
inline int sign(double x,double eps=1e-10)
{
    return(x<-eps?-1:x>eps);
}
point p[710];
double a[710];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        int ans=1;
        for (int i=1;i<=n;i++)
        {
            int m=0;
            for (int j=1;j<=n;j++)
            {
                if (i==j)
                    continue;
                a[++m]=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
            }
            sort(a+1,a+m+1);
            for (int j=1,k;j<=m;j=k)
            {
                int sum=0;
                for (k=j;sign(a[j]-a[k])==0 && k<=m;k++)
                    sum++;
                ans=max(ans,sum+1);
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

