#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
struct cube
{
    int len,wid,hei,kind;
};
inline bool operator <(const cube &a,const cube &b)
{
    return(a.len<b.len || a.len==b.len && (a.wid<b.wid || a.wid==b.wid && a.kind>b.kind));
}
inline bool can(const cube &a,const cube &b)
{
    if (a.kind==0)
        return(a.len>=b.len && a.wid>=b.wid);
    if (a.kind==1)
        return(a.len>=b.len && a.wid>b.wid || a.len>b.len && a.wid>=b.wid);
    return(a.len>b.len && a.wid>b.wid);
}
cube a[1010];
ll f[1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&a[i].len,&a[i].wid,&a[i].hei,&a[i].kind);
            if (a[i].len<a[i].wid)
                swap(a[i].len,a[i].wid);
        }
        sort(a+1,a+n+1);
        f[0]=0;
        ll ans=0;
        for (int i=1;i<=n;i++)
        {
            f[i]=0;
            for (int j=0;j<i;j++)
                if (can(a[i],a[j]))
                {
                    f[i]=max(f[i],f[j]+a[i].hei);
                    ans=max(ans,f[i]);
                }
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

