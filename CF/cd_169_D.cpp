#include <cstdio>
#include <algorithm>
using namespace std;
int n,K,h,ans[100010],p[100010],c[100010],m[100010],v[100010];
inline bool cmp(int x,int y)
{
    return(m[x]<m[y] || m[x]==m[y] && v[x]<v[y]);
}
bool check(double T)
{
    int t=1;
    for (int i=1;i<=n;i++)
    {
        int x=c[i];
        double tmp=t*h/double(v[x]);
        if (tmp<=T)
        {
            p[t++]=x;
            if (t==K+1)
                return(true);
        }
    }
    return(false);
}
int main()
{
    scanf("%d%d%d",&n,&K,&h);
    for (int i=1;i<=n;i++)
    {
        c[i]=i;
        scanf("%d",&m[i]);
    }
    for (int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    sort(c+1,c+n+1,cmp);
    double l=0,r=K*h;
    for (int T=1;T<=100;T++)
    {
        double mid=(l+r)/2;
        if (check(mid))
        {
            r=mid;
            for (int i=1;i<=K;i++)
                ans[i]=p[i];
        }
        else
            l=mid;
    }
    for (int i=1;i<=K;i++)
        printf("%d%c",ans[i],i==K?'\n':' ');
    return(0);
}

