#include <cstdio>
#include <string>
using namespace std;
const int c[3][2]={{1,0},{0,-1},{0,1}};
int n,m,N,M,ans,L[110],R[110];
string a[110],b[10110];
char s[1010];
bool vis[10110][1010];
bool check(int x,int y)
{
    if (y+m-1>M)
        return(false);
    for (int i=n;i;i--)
    {
        if (x==0)
            return(true);
        for (int j=1;j<=m;j++)
            if (a[i][j]=='#' && b[x][y+j-1]=='#')
                return(false);
        x--;
    }
    return(true);
}
void dfs(int x0,int y0)
{
    ans=max(ans,x0);
    vis[x0][y0]=false;
    for (int i=0;i<3;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>0 && x<=N && y>0 && y<=M && vis[x][y])
            dfs(x,y);
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",s);
            a[i]=string(" ")+s;
        }
        scanf("%d%d",&N,&M);
        for (int i=1;i<=N;i++)
        {
            scanf("%s",s);
            b[i]=string(" ")+s;
        }
        for (int i=N+1;i<=N+n;i++)
            b[i]=" "+string(M,'.');
        N+=n;
        for (int i=0;i<=N;i++)
            for (int j=1;j<=M;j++)
                vis[i][j]=check(i,j);
        ans=0;
        for (int i=1;i<=M-m+1;i++)
            if (vis[0][i])
                dfs(0,i);
        if (ans==N)
            printf("The key can fall through.\n");
        else
            printf("The key falls to depth %d.\n",ans);
    }
    return(0);
}

