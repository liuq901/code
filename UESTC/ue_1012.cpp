#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool f[1010];
int a[1010];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        int m,ans;
        scanf("%d",&m);
        ans=m;
        for (int T=1;T<=n;T++)
        {
            if (5-a[T]>=ans)
                break;
            memset(f,0,sizeof(f));
            f[m]=true;
            for (int i=1;i<=n;i++)
            {
                if (i==T)
                    continue;
                for (int j=5;j<=m-a[i];j++)
                    if (f[j+a[i]])
                        f[j]=true;
            }
            for (int i=5;i<=m;i++)
                if (f[i])
                {
                    ans=min(ans,i-a[T]);
                    break;
                }
        }
        printf("%d\n",ans);
    }
    return(0);
}

