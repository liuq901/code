#include <cstdio>
#include <algorithm>
using namespace std;
struct data
{
    int t,d;
};
inline bool operator <(const data &a,const data &b)
{
    return(a.t>b.t);
}
data a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i].d,&a[i].t);
        sort(a+1,a+n+1);
        int ans=0,now=0;
        for (int i=1;i<=n;i++)
        {
            now+=a[i].d;
            ans=max(ans,now+a[i].t);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

