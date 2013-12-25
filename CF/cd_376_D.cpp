#include <cstdio>
#include <algorithm>
using namespace std;
char a[5010][5010];
int f[5010][5010],s[5010][5010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=n;i++)
    {
        int prev=-1;
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]=='0')
            {
                prev=-1;
                continue;
            }
            if (prev==-1)
                prev=j;
            if (j==m || a[i][j+1]=='0')
                s[prev][j]++;
        }
    }
    for (int i=1;i<=m;i++)
        for (int j=i;j<=m;j++)
            f[i][j]=f[i-1][j]+s[i][j];
    int ans=0;
    for (int i=1;i<=m;i++)
    {
        int cnt=0;
        for (int j=m;j>=i;j--)
        {
            cnt+=f[i][j];
            ans=max(ans,cnt*(j-i+1));
        }
    }
    printf("%d\n",ans);
    return(0);
}

