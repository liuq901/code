#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[3010],c[3010];
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
        fill(c+1,c+n,0);
        for (int i=2;i<=n;i++)
        {
            int t=abs(a[i]-a[i-1]);
            if (t>=1 && t<n)
                c[t]++;
        }
        printf("%solly\n",count(c+1,c+n,1)==n-1?"J":"Not j");
    }
    return(0);
}

