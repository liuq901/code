#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,ans,tot,idx,vis[10][10],a[10][10],tmp[100][10][10];
int best()
{
    bool f[6]={0};
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=-1) 
                f[a[i][j]]=true;
    return(count(f,f+6,true));
}
void save()
{
    tot++;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            tmp[tot][i][j]=a[i][j];
}
void load()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=tmp[tot][i][j];
    tot--;
}
int color(int x0,int y0,int value)
{
    if (a[x0][y0]!=-1 && a[x0][y0]!=value || vis[x0][y0]==idx)
        return(0);
    vis[x0][y0]=idx;
    int ret=0;
    if (a[x0][y0]!=-1)
    {
        a[x0][y0]=-1;
        ret=1;
    }
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>=1 && x<=n && y>=1 && y<=n)
            ret+=color(x,y,value);
    }
    return(ret);
}
bool dfs(int dep)
{
    if (dep+best()>ans)
        return(false);
    if (dep==ans)
        return(true);
    for (int i=0;i<6;i++)
    {
        save();
        idx++;
        if (color(1,1,i)!=0 && dfs(dep+1))
            return(true);
        load();
    }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        ans=tot=idx=0;
        memset(vis,0,sizeof(vis));
        idx++;
        color(1,1,a[1][1]);
        while (!dfs(0))
            ans++;
        printf("%d\n",ans);
    }
    return(0);
}

