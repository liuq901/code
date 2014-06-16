#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110],f[110][110][110];
int dp(int l,int r,int v)
{
    if (f[l][r][v]!=-1)
        return(f[l][r][v]);
    int &ret=f[l][r][v];
    if (l==r)
        ret=0;
    else
    {
        ret=1<<30;
        for (int k=l+1;k<=r;k++)
            ret=min(ret,dp(l,k-1,v)+dp(k,r,a[k])+(a[k]!=v));
    }
    return(ret);
}
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
        memset(f,-1,sizeof(f));
        static int id=0;
        printf("Case %d: %d\n",++id,dp(1,n,a[1])+1);
    }
    return(0);
}

