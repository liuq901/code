#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    return(0);
}

