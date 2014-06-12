#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x<n)
                a[min(x,n-x-1)]++;
        }
        bool flag=true;
        for (int i=1;i<=n;i++)
        {
            int t=min(i-1,n-i);
            if (!a[t])
            {
                flag=false;
                break;
            }
            a[t]--;
        }
        static int id=0;
        printf("Case %d: %s\n",++id,flag?"yes":"no");
    }
    return(0);
}

