#include <cstdio>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int now,ans,n,m,a[30][30];
void dfs(int x0,int y0)
{
    if (now>=ans)
        return;
    if (a[x0][y0]==3)
    {
        ans=now;
        return;
    }
    for (int i=0;i<4;i++)
    {
        int x=x0,y=y0;
        while (1)
        {
            x+=c[i][0],y+=c[i][1];
            if (x==0 || x>n || y==0 || y>m || a[x][y]==1 || a[x][y]==3)
                break;
        }
        if (x>0 && x<=n && y>0 && y<=m)
        {
            if (a[x][y]==3)
            {
                now++;
                dfs(x,y);
                now--;
            }
            if (a[x][y]==1 && (x!=x0+c[i][0] || y!=y0+c[i][1]))
            {
                a[x][y]=0;
                now++;
                dfs(x-c[i][0],y-c[i][1]);
                now--;
                a[x][y]=1;
            }
        }
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&m,&n);
        if (n==0 && m==0)
            break;
        int Sx,Sy;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                if (a[i][j]==2)
                    Sx=i,Sy=j;
            }
        ans=11;
        dfs(Sx,Sy);
        if (ans==11)
            ans=-1;
        printf("%d\n",ans);
    }
    return(0);
}

