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
    {
        int k=i;
        for (int j=i;j<=n;j++)
            if (a[j]<a[k])
                k=j;
        if (k!=i)
        {
            ans++;
            swap(a[k],a[i]);
        }
    }
    for (int i=1;i<=n;i++)
        printf("%d%c",a[i],i==n?'\n':' ');
    printf("%d\n",ans);
    return(0);
}

