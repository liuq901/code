#include <cstdio>
#include <algorithm>
using namespace std;
int a[20010],b[20010];
double f[20010];
bool check(double mid,int n,int m)
{
    for (int i=1;i<=n;i++)
        f[i]=a[i]-b[i]*mid;
    sort(f+1,f+n+1);
    double sum=0;
    for (int i=m+1;i<=n;i++)
        sum+=f[i];
    return(sum>=0);
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
            scanf("%d%d",&a[i],&b[i]);
        double l=0,r=1;
        for (int _=1;_<=50;_++)
        {
            double mid=(l+r)/2;
            if (check(mid,n,m))
                l=mid;
            else
                r=mid;
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,(l+r)*50);
    }
    return(0);
}

