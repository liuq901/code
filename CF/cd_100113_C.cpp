#include <cstdio>
#include <string>
#include <bitset>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool Vis[1000010];
string a[100010];
char buf[1000010];
int n,m,q[1000010][2];
inline bool &vis(int x,int y)
{
    return(Vis[(x-1)*m+y]);
}
int bfs(int Sx,int Sy)
{
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    vis(Sx,Sy)=true;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>=1 && x<=n && y>=1 && y<=m && a[x][y]=='1' && !vis(x,y))
            {
                q[++r][0]=x,q[r][1]=y;
                vis(x,y)=true;
            }
        }
    }
    return(r);
}
int main()
{
    freopen("blot.in","r",stdin);
    freopen("blot.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%s",buf);
        a[i]=string(" ")+buf;
    }
    int sum=0,ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='1' && !vis(i,j))
            {
                sum++;
                ans=max(ans,bfs(i,j));
            }
    printf("%d %d\n",sum,ans);
    return(0);
}

