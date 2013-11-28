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
        sort(a+1,a+n+1);
        int sum=0;
        for (int i=1;i<=n/2+1;i++)
            sum+=a[i]/2+1;
        printf("%d\n",sum);
    }
    return(0);
}

