#include <cstdio>
typedef long long ll;
int n,a[200010],c[200010];
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret+=c[i];
    return(ret);
}
void insert(int x)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]++;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        n+=m;
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[x]=y;
            c[i]=0;
        }
        ll ans=0;
        for (int i=n;i;i--)
        {
            ans+=query(a[i]);
            insert(a[i]);
        }
        static int id=0;
        printf("Case %d: %lld\n",++id,ans);
    }
    return(0);
}

