#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=500000;
int c[500010];
void insert(int x)
{
    x+=200000;
    for (int i=x;i<=N;i+=i&-i)
        c[i]++;
}
int query(int x)
{
    x+=200000;
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
int a[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(c,0,sizeof(c));
        ll ans=0;
        for (int i=n;i;i--)
        {
            for (int j=1;j<i;j++)
                for (int k=j+1;k<i;k++)
                    ans+=query(a[i]+a[j]+a[k]-1);
            for (int j=i+1;j<=n;j++)
                for (int k=j+1;k<=n;k++)
                    insert(a[k]-a[i]-a[j]);
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

