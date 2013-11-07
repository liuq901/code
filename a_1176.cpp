#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair <int,int> state;
const int inf=1000000000;
int tot,S,a[40][40],s[40][40];
state f[40][40][40][40];
bool vis[40][40][40][40];
int sum(int x0,int y0,int x1,int y1)
{
    x0--,y0--;
    return(s[x1][y1]-s[x1][y0]-s[x0][y1]+s[x0][y0]);
}
state dp(int x0,int y0,int x1,int y1)
{
    if (vis[x0][y0][x1][y1])
        return(f[x0][y0][x1][y1]);
    vis[x0][y0][x1][y1]=true;
    state &ret=f[x0][y0][x1][y1];
    ret=tot-sum(x0,y0,x1,y1)<=S?make_pair(1,S-tot+sum(x0,y0,x1,y1)):make_pair(-inf,-inf);
    for (int i=x0;i<x1;i++)
    {
        state x=dp(x0,y0,i,y1),y=dp(i+1,y0,x1,y1);
        state now=make_pair(x.first+y.first,min(x.second,y.second));
        ret=max(ret,now);
    }
    for (int i=y0;i<y1;i++)
    {
        state x=dp(x0,y0,x1,i),y=dp(x0,i+1,x1,y1);
        state now=make_pair(x.first+y.first,min(x.second,y.second));
        ret=max(ret,now);
    }
    return(ret);
}
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d%d",&n,&m,&S);
        if (n==0 && m==0 && S==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
            }
        tot=s[n][m];
        memset(vis,0,sizeof(vis));
        state ans=dp(1,1,n,m);
        printf("%d %d\n",ans.first,ans.second);
    }
    return(0);
}

