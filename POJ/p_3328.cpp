#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int move[2][9][2],q[50000][3],d[70][70][2];
char a[70][70];
void init()
{
    for (int i=0;i<5;i++)
    {
        move[0][i][0]=move[1][i][0]=i-2;
        move[0][i][1]=-1;
        move[1][i][1]=1;
    }
    for (int i=5;i<8;i++)
    {
        move[0][i][0]=move[1][i][0]=i-6;
        move[0][i][1]=-2;
        move[1][i][1]=2;
    }
    move[0][8][0]=move[1][8][0]=0;
    move[0][8][1]=-3;
    move[1][8][1]=3;
}
bool in[70][70][2];
int spfa(int n,int m)
{
    memset(d,63,sizeof(d));
    int l=0,r=0,inf=d[0][0][0];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='S')
            {
                q[++r][0]=i,q[r][1]=j,q[r][2]=0;
                q[++r][0]=i,q[r][1]=j,q[r][2]=1;
                d[i][j][0]=d[i][j][1]=0;
                in[i][j][0]=in[i][j][1]=true;
            }
    while (l!=r)
    {
        l++;
        if (l>50000)
            l=1;
        int x0=q[l][0],y0=q[l][1],op=q[l][2];
        in[x0][y0][op]=false;
        for (int i=0;i<9;i++)
        {
            int x=x0+move[op][i][0],y=y0+move[op][i][1];
            if (x<=0 || x>n || y<=0 || y>m || a[x][y]=='X')
                continue;
            if (a[x][y]=='T')
            {
                d[x][y][0]=min(d[x][y][0],d[x0][y0][op]);
                continue;
            }
            if (d[x0][y0][op]+a[x][y]-'0'<d[x][y][1-op])
            {
                d[x][y][1-op]=d[x0][y0][op]+a[x][y]-'0';
                if (!in[x][y][1-op])
                {
                    in[x][y][1-op]=true;
                    r++;
                    if (r>50000)
                        r=1;
                    q[r][0]=x,q[r][1]=y,q[r][2]=1-op;
                }
            }
        }
    }
    int ans=inf;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (a[i][j]=='T')
                ans=min(ans,d[i][j][0]);
    if (ans==inf)
        ans=-1;
    return(ans);
}
int main()
{
    init();
    while (1)
    {
        int n,m;
        scanf("%d%d",&m,&n);
        if (!n && !m)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                cin>>a[i][j];
        printf("%d\n",spfa(n,m));
    }
    return(0);
}

