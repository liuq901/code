#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int dx,dy,a[20][20],f[20][20];
bool vis[20][20];
void dfs(int x0,int y0)
{
    vis[x0][y0]=true;
    for (int i=0;i<4;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x>0 && x<=10 && y>0 && y<=10 && !vis[x][y] && f[x][y]==f[x0][y0])
            dfs(x,y);
    }
}
bool check()
{
    memset(vis,0,sizeof(vis));
    int x=0,y=0;
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
            if (a[i][j]==1 && !vis[i][j])
            {
                dfs(i,j);
                if (f[i][j]==1)
                    x++;
                else
                    y++;
            }
    return(x==1 && y==1);
}
void work1(int x0,int y0,int turn,int rotate,int &x,int &y)
{
    if (turn)
        x0=11-x0;
    for (int i=0;i<rotate;i++)
    {
        int p,q;
        p=x0,q=y0;
        x0=q,y0=11-p;
    }
    x=x0+dx,y=y0+dy;
}
void work2(int x0,int y0,int turn,int rotate,int &x,int &y)
{
    x0-=dx,y0-=dy;
    for (int i=rotate;i<4;i++)
    {
        int p,q;
        p=x0,q=y0;
        x0=q,y0=11-p;
    }
    if (turn)
        x0=11-x0;
    x=x0,y=y0;
}
bool dfs(int x,int y,int turn,int rotate)
{
    if (x==11)
        return(check());
    if (y==11)
        return(dfs(x+1,1,turn,rotate));
    if (a[x][y]==0 || f[x][y]!=0)
        return(dfs(x,y+1,turn,rotate));
    int p,q;
    f[x][y]=1;
    work1(x,y,turn,rotate,p,q);
    if (p>0 && p<=10 && q>0 && q<=10 && a[p][q]==1 && !f[p][q])
    {
        f[p][q]=2;
        if (dfs(x,y+1,turn,rotate))
            return(true);
        f[p][q]=0;
    }
    f[x][y]=2;
    work2(x,y,turn,rotate,p,q);
    if (p>0 && p<=10 && q>0 && q<=10 && a[p][q]==1 && !f[p][q])
    {
        f[p][q]=1;
        if (dfs(x,y+1,turn,rotate))
            return(true);
        f[p][q]=0;
    }
    f[x][y]=0;
    return(false);
}
int main()
{
    while (1)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        if (n==0 && m==0)
            break;
        memset(a,0,sizeof(a));
        int sum=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                sum+=a[i][j];
            }
        if (sum&1)
            printf("NO\n");
        else
        {
            int x,y;
            bool flag=false,fail=true;
            for (int i=1;i<=n;i++)
                for (int j=1;j<=m;j++)
                {
                    if (a[i][j]==0)
                        continue;
                    if (!flag)
                    {
                        flag=true;
                        x=i,y=j;
                        continue;
                    }
                    memset(f,0,sizeof(f));
                    f[x][y]=1;
                    f[i][j]=2;
                    for (int turn=0;turn<2;turn++)
                    {
                        for (int rotate=0;rotate<4;rotate++)
                        {
                            dx=i-x,dy=j-y;
                            if (dfs(1,1,turn,rotate))
                            {
                                fail=false;
                                goto print;
                            }
                            int p=x,q=y;
                            x=q,y=11-p;
                        }
                        x=11-x;
                    }
                }
print:
            printf("%s\n",fail?"NO":"YES");
        }
    }
    return(0);
}

