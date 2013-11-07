#include <cstdio>
#include <algorithm>
using namespace std;
int limit[310],a[310][310],s[310][310];
inline int get(int x1,int y1,int x2,int y2)
{
    return(s[x2][y2]-s[x1-1][y2]-s[x2][y1-1]+s[x1-1][y1-1]);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            if (a[i][j]==0)
                limit[j]=i;
            int up=0;
            for (int k=j;k;k--)
            {
                up=max(up,limit[k]);
                ans=max(ans,get(up+1,k,i,j));
            }
        }
    printf("%d\n",ans);
    return(0);
}

