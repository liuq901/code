#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110],f[110][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,K;
        scanf("%d%d%d",&n,&m,&K);
        for (int i=1;i<=n;i++)
            scanf("%*d%d",&a[i]);
        sort(a+1,a+n+1);
        memset(f,0,sizeof(f));
        for (int i=1;i<=K;i++)
            for (int j=1;j<=n;j++)
            {
                int p=0;
                for (int k=j;k;k--)
                   if (a[k]<a[j]-m)
                   {
                       p=k;
                       break;
                   }
                f[i][j]=max(f[i][j-1],f[i-1][p]+j-p);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[K][n]);
    }
    return(0);
}

