#include <cstdio>
#include <algorithm>
using namespace std;
int a[60];
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
        sort(a+1,a+n+1);
        int ans=0;
        for (int i=1,j;i<=n;i=j)
        {
            int cnt=0;
            for (j=i;j<=n && a[i]==a[j];j++)
                cnt++;
            ans+=(cnt+a[i])/(a[i]+1)*(a[i]+1);
        }
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

