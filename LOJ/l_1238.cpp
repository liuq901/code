#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
char a[30][30];
int d[30][30],q[410][2];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        int Sx,Sy;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]=='h')
                    Sx=i,Sy=j;
        int l,r;
        q[l=r=1][0]=Sx,q[1][1]=Sy;
        memset(d,-1,sizeof(d));
        d[Sx][Sy]=0;
        while (l<=r)
        {
            int x0=q[l][0],y0=q[l++][1];
            for (int i=0;i<4;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (a[x][y]!='#' && a[x][y]!='m' && d[x][y]==-1)
                {
                    d[x][y]=d[x0][y0]+1;
                    q[++r][0]=x,q[r][1]=y;
                }
            }
        }
        int ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (a[i][j]>='a' && a[i][j]<='c')
                    ans=max(ans,d[i][j]);
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

