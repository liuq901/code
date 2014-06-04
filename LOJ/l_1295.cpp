#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct data
{
    int v,k,c,l;
};
inline bool operator <(const data &a,const data &b)
{
    return(a.v<b.v);
}
data a[1010];
int f[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
        sort(a+1,a+n+1);
        memset(f,63,sizeof(f));
        f[0]=0;
        for (int i=1;i<=n;i++)
        {
            int sum=a[i].l;
            for (int j=i-1;j>=0;j--)
            {
                f[i]=min(f[i],f[j]+a[i].k+a[i].c*sum);
                sum+=a[j].l;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n]);
    }
    return(0);
}

