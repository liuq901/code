#include <cstdio>
#include <algorithm>
using namespace std;
int a[510];
bool f[510][510];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            f[i][j]=__gcd(a[i],a[j])==1;
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=j+1;k<=n;k++)
                ans+=f[i][j]==f[i][k] && f[i][j]==f[j][k];
    printf("%d\n",ans);
    return(0);
}

