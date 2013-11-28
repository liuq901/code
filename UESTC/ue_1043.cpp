#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000010];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        reverse(a+1,a+n+1);
        for (int i=1;i<=m;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return(0);
}

