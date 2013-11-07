#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[1010],f[1010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    memset(f,63,sizeof(f));
    f[0]=0;
    for (int i=1;i<=n;i++)
    {
        if (i<n && a[i]==a[i+1])
            continue;
        for (int j=0;j<i;j++)
        {
            if (i-j>m/a[i])
                continue;
            f[i]=min(f[i],f[j]+1);
        }
    }
    for (int i=n;i>=0;i--)
        if (f[i]<1000000)
        {
            printf("%d %d\n",i,f[i]);
            break;
        }
    return(0);
}

