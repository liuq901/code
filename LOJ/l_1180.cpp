#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110],b[110],f[110][110];
bool check(int n,int m,int limit)
{
    memset(f,-63,sizeof(f));
    f[0][0]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=m;j++)
            for (int k=0;k<=j;k++)
            {
                if (a[i]*k>limit)
                    break;
                f[i][j]=max(f[i][j],f[i-1][j-k]+(limit-a[i]*k)/b[i]);
            }
    return(f[n][m]>=m);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        int l=0,r=50000,ans;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(n,m,mid))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

