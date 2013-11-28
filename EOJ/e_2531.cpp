#include <cstdio>
#include <algorithm>
using namespace std;
int a[2010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int l=1,r=n,ans=0;
        while (l<=r)
        {
            ans++;
            if (a[l]+a[r]<=K)
                l++,r--;
            else
                r--;
        }
        printf("%d\n",ans);
    }
    return(0);
}

