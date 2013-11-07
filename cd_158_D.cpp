#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[20010];
int work(int p)
{
    if (p<3)
        return(-1<<30);
    int d=n/p,ret=-1<<30;
    for (int i=0;i<d;i++)
    {
        int sum=0,t=i;
        for (int j=1;j<=p;j++)
        {
            sum+=a[t];
            t=(t+d)%n;
        }
        ret=max(ret,sum);
    }
    return(ret);
}
int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=-1<<30;
    for (int i=1;i*i<=n;i++)
        if (n%i==0)
            ans=max(ans,max(work(i),work(n/i)));
    printf("%d\n",ans);
    return(0);
}

