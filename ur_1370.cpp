#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    m%=n;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=m;i++)
        rotate(a+1,a+2,a+n+1);
    for (int i=1;i<=10;i++)
        printf("%d",a[i]);
    printf("\n");
    return(0);
}

