#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const double p=0.6180339887498949;
int a[30010];
inline int sign(double x,double eps=1e-12)
{
    return(x<-eps?-1:x>eps);
}
void update(int &x,int &y,int u,int v)
{
    double t1=fabs(double(x)/y-p);
    double t2=fabs(double(u)/v-p);
    if (sign(t1-t2)>0)
        x=u,y=v;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int ans0=a[1],ans1=a[2];
    for (int i=1;i<=n;i++)
    {
        int x=int(a[i]*p),t=lower_bound(a+1,a+n+1,x)-a-1;
        for (int j=t-20;j<=t+20;j++)
            if (j>=1 && j<i)
                update(ans0,ans1,a[j],a[i]);
    }
    printf("%d\n%d\n",ans0,ans1);
    return(0);
}

