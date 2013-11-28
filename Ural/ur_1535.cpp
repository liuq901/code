#include <cstdio>
#include <algorithm>
using namespace std;
int a[50010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        a[i]=i;
    for (int i=1;i<=n/2;i++)
        if (i%2==0)
            swap(a[i],a[n-i+1]);
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    a[1]=1;
    for (int i=2;i<=(n+1)/2;i++)
        a[i]=a[i-1]+2;
    a[n]=2;
    for (int i=n-1;i>(n+1)/2;i--)
        a[i]=a[i+1]+2;
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    return(0);
}

