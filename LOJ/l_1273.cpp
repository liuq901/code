#include <cstdio>
#include <algorithm>
using namespace std;
int a[50010];
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
        int t=1;
        for (int i=1;i<=n;i++)
        {
            while (t<=n && a[t]<=i)
                t++;
            if (i==t-1)
            {
                static int id=0;
                printf("Case %d: %d\n",++id,i);
                break;
            }
        }
    }
    return(0);
}

