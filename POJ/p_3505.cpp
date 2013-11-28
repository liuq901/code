#include <cstdio>
#include <algorithm>
using namespace std;
int a[60][60],pos[2501][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,L,m=0;
        scanf("%d%d",&n,&L);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=L;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]!=-1)
                {
                    m=max(m,a[i][j]);
                    pos[a[i][j]][0]=i;
                    pos[a[i][j]][1]=j;
                }
            }
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            int x=pos[i][0],y=pos[i][1],dis=min(y-1,L-y+1);
            ans+=dis*5+(x-1)*20;
            rotate(a[x]+1,a[x]+y,a[x]+L+1);
            for (int j=1;j<=L;j++)
                if (a[x][j]!=-1)
                    pos[a[x][j]][1]=j;
        }
        printf("%d\n",ans);
    }
    return(0);
}

