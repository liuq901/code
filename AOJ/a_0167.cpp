#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
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
        int ans=0;
        for (int i=n;i;i--)
            for (int j=2;j<=i;j++)
                if (a[j-1]>a[j])
                {
                    swap(a[j-1],a[j]);
                    ans++;
                }
        printf("%d\n",ans);
    }
    return(0);
}

