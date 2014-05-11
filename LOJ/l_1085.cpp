#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int mod=1000000007;
int n,a[100010],c[100010];
void modify(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]=(c[i]+value)%mod;
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret=(ret+c[i])%mod;
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        vector <int> value;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            value.push_back(a[i]);
        }
        sort(value.begin(),value.end());
        value.erase(unique(value.begin(),value.end()),value.end());
        for (int i=1;i<=n;i++)
            a[i]=lower_bound(value.begin(),value.end(),a[i])-value.begin()+1;
        memset(c,0,sizeof(c));
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int now=(query(a[i]-1)+1)%mod;
            ans=(ans+now)%mod;
            modify(a[i],now);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

