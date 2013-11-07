#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int s[110],a[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
            for (int k=i;k<j;k++)
                s[k]+=a[i][j];
    for (int i=1;i<n;i++)
        ans=max(ans,s[i]);
    memset(s,0,sizeof(s));
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
            for (int k=j;k<i;k++)
                s[k]+=a[i][j];
    for (int i=1;i<n;i++)
        ans=max(ans,s[i]);
    printf("%d\n",(ans+35)/36);
    return(0);
}

