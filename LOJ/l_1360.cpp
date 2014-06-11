#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int n=200000;
int c[200010],f[200010];
void insert(int x,int value)
{
    for (int i=x;i<=n;i+=i&-i)
        c[i]=max(c[i],value);
}
int query(int x)
{
    int ret=0;
    for (int i=x;i;i-=i&-i)
        ret=max(ret,c[i]);
    return(ret);
}
int a[200010],b[200010],v[200010],p[200010];
inline bool cmp(int x,int y)
{
    return(a[x]+b[x]<a[y]+b[y]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%d",&m);
        memset(c,0,sizeof(c));
        memset(f,0,sizeof(f));
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&v[i]);
            p[i]=i;
        }
        sort(p+1,p+m+1,cmp);
        for (int i=1;i<=m;i++)
        {
            int x=a[p[i]],y=b[p[i]],z=v[p[i]];
            f[x+y]=max(f[x+y],query(x)+z);
            insert(x+y,f[x+y]);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,query(n));
    }
    return(0);
}

