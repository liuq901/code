#include <cstdio>
#include <algorithm>
using namespace std;
char a[2010][2010];
int n,m,x0,y0,x1,y1,L[2010][2010],U[2010][2010],l[2010][2010],u[2010][2010],s[2010][2010];
int get(int x0,int y0,int x1,int y1)
{
    return(s[x1][y1]-s[x0-1][y1]-s[x1][y0-1]+s[x0-1][y0-1]);
}
void update(int u,int v,int x,int y)
{
    int sum;
    if (u==x && v==y)
        sum=a[x][y]=='w';
    else
        sum=get(u,v,u,y-1)+get(u,y,x-1,y)+get(x,v+1,x,y)+get(u+1,v,x,v);
    if (sum==s[n][m] && (x0==0 || x-u<x1-x0))
        x0=u,y0=v,x1=x,y1=y;
}
bool on(int x,int y,int x0,int y0,int x1,int y1)
{
    if (x==x0 || x==x1)
        return(y>=y0 && y<=y1);
    if (y==y0 || y==y1)
        return(x>=x0 && x<=x1);
    return(false);
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
            l[i][j]=l[i][j-1];
            u[i][j]=u[i-1][j];
            L[i][j]=L[i][j-1];
            U[i][j]=U[i-1][j];
            if (a[i][j]=='w')
            {
                if (l[i][j]==0)
                    l[i][j]=j;
                if (u[i][j]==0)
                    u[i][j]=i;
                s[i][j]++;
            }
            if (u[i][j]!=0 && L[i][j]==0)
                L[i][j]=j;
            if (l[i][j]!=0 && U[i][j]==0)
                U[i][j]=i;
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            int dx=-1,dy=-1;
            if (L[i][j]!=0)
                dy=j-L[i][j]+1;
            if (U[i][j]!=0)
                dx=i-U[i][j]+1;
            if (dx==-1 && dy==-1)
                continue;
            if (dx==-1)
                dx=dy;
            if (dy==-1)
                dy=dx;
            int d=max(dx,dy);
            if (i-d+1>=1 && j-d+1>=1)
                update(i-d+1,j-d+1,i,j);
        }
    if (x0==0)
        printf("-1\n");
    else
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                if (a[i][j]=='.' && on(i,j,x0,y0,x1,y1))
                    a[i][j]='+';
            printf("%s\n",a[i]+1);
        }
    return(0);
}

