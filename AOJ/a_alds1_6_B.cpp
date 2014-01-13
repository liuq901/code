#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int x=a[n],i=0;
    for (int j=1;j<n;j++)
        if (a[j]<=x)
            swap(a[++i],a[j]);
    swap(a[++i],a[n]);
    for (int j=1;j<=n;j++)
    {
        if (i==j)
            printf("[");
        printf("%d",a[j]);
        if (i==j)
            printf("]");
        printf("%c",j==n?'\n':' ');
    }
    return(0);
}

