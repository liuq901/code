#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int l[310],r[310],a[310],f[310][310];
void add(int x,int y)
{
    if (l[x]==-1)
        l[x]=y;
    else
    {
        int p=l[x];
        while (r[p]!=-1)
            p=r[p];
        r[p]=y;
    }
}
int dp(int x,int y)
{
    if (x==-1)
        return(0);
    if (f[x][y]!=-1)
        return(f[x][y]);
    int &ret=f[x][y];
    for (int i=0;i<y;i++)
        ret=max(ret,dp(l[x],i)+dp(r[x],y-i-1)+a[x]);
    ret=max(ret,dp(r[x],y));
    return(ret);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(l,-1,sizeof(l));
    memset(r,-1,sizeof(r));
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d%d",&x,&a[i]);
        add(x,i);
    }
    memset(f,-1,sizeof(f));
    printf("%d\n",dp(0,m+1));
    return(0);
}

