#include <cstdio>
#include <algorithm>
using namespace std;
int a[30];
int main()
{
    int n,T;
    scanf("%d%d",&n,&T);
    while (T--)
    {
        int m;
        scanf("%d",&m);
        m%=n;
        for (int i=1;i<=n;i++)
            a[i]=i;
        rotate(a+1,a+n-m+1,a+n+1);
        for (int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return(0);
}

