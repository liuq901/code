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
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=n;j>i;j--)
            if (a[j-1]>a[j])
            {
                swap(a[j-1],a[j]);
                ans++;
            }
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    printf("%d\n",ans);
    return(0);
}

