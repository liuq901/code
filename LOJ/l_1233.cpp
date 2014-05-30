#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool ans[100010];
int a[110],f[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        memset(ans,0,sizeof(ans));
        ans[0]=true;
        for (int i=1;i<=n;i++)
        {
            int K;
            scanf("%d",&K);
            for (int j=0;j<=m;j++)
                if (ans[j])
                    f[j]=0;
                else if (j<a[i])
                    f[j]=K+1;
                else
                    f[j]=f[j-a[i]]+1;
            for (int j=0;j<=m;j++)
                ans[j]=f[j]<=K;
        }
        static int id=0;
        printf("Case %d: %d\n",++id,count(ans+1,ans+m+1,true));
    }
    return(0);
}

