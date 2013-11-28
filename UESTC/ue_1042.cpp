#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000010];
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
        for (int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return(0);
}

