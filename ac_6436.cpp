#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int fa[20010],b[20010],s[20010],q[20010],a[40010][2];
ll ans[20010];
void bfs(int n)
{
    int l,r;
    q[l=r=1]=1;
    while (l<=r)
    {
        int x=q[l++];
        for (int i=b[x];i;i=a[i][1])
        {
            int y=a[i][0];
            if (y==fa[x])
                continue;
            fa[y]=x;
            q[++r]=y;
        }
    }
    for (int i=n;i;i--)
    {
        int x=q[i];
        s[x]=1;
        ans[x]=0;
        for (int j=b[x];j;j=a[j][1])
        {
            int y=a[j][0];
            if (y==fa[x])
                continue;
            s[x]+=s[y];
            ans[x]+=s[y]*(n-s[x]);
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(b,0,sizeof(b));
        for (int i=1;i<n;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            a[i][0]=y,a[i][1]=b[x],b[x]=i;
            a[i+n][0]=x,a[i+n][1]=b[y],b[y]=i+n;
        }
        bfs(n);
        static int id=0;
        printf("Case #%d: %lld\n",++id,*max_element(ans+1,ans+n+1));
    }
    return(0);
}

