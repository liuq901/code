#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
const int back[4]={1,0,3,2},left[4]={2,3,1,0},right[4]={3,2,0,1};
struct state
{
    int x,y,direc;
    state(){}
    state(int x,int y,int d):x(x),y(y),direc(d){}
};
state q[2010];
int a[40][40],d[40][40][4];
bool in[40][40][4];
int main()
{
    while (1)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        int c0,c1,c2,c3;
        scanf("%d%d%d%d",&c0,&c1,&c2,&c3);
        int l,r;
        l=0,r=1;
        q[1]=state(1,1,3);
        memset(d,63,sizeof(d));
        d[1][1][3]=0;
        in[1][1][3]=true;
        while (l!=r)
        {
            l=l==2000?1:l+1;
            int x0=q[l].x,y0=q[l].y,now=q[l].direc;
            in[x0][y0][now]=false;
            int x,y,direc;
            direc=now,x=x0+c[direc][0],y=y0+c[direc][1];
            if (x>0 && x<=n && y>0 && y<=m && d[x0][y0][now]+(a[x0][y0]==0?0:c0)<d[x][y][direc])
            {
                d[x][y][direc]=d[x0][y0][now]+(a[x0][y0]==0?0:c0);
                if (!in[x][y][direc])
                {
                    in[x][y][direc]=true;
                    q[r=r==2000?1:r+1]=state(x,y,direc);
                }
            }
            direc=right[now],x=x0+c[direc][0],y=y0+c[direc][1];
            if (x>0 && x<=n && y>0 && y<=m && d[x0][y0][now]+(a[x0][y0]==1?0:c1)<d[x][y][direc])
            {
                d[x][y][direc]=d[x0][y0][now]+(a[x0][y0]==1?0:c1);
                if (!in[x][y][direc])
                {
                    in[x][y][direc]=true;
                    q[r=r==2000?1:r+1]=state(x,y,direc);
                }
            }
            direc=back[now],x=x0+c[direc][0],y=y0+c[direc][1];
            if (x>0 && x<=n && y>0 && y<=m && d[x0][y0][now]+(a[x0][y0]==2?0:c2)<d[x][y][direc])
            {
                d[x][y][direc]=d[x0][y0][now]+(a[x0][y0]==2?0:c2);
                if (!in[x][y][direc])
                {
                    in[x][y][direc]=true;
                    q[r=r==2000?1:r+1]=state(x,y,direc);
                }
            }
            direc=left[now],x=x0+c[direc][0],y=y0+c[direc][1];
            if (x>0 && x<=n && y>0 && y<=m && d[x0][y0][now]+(a[x0][y0]==3?0:c3)<d[x][y][direc])
            {
                d[x][y][direc]=d[x0][y0][now]+(a[x0][y0]==3?0:c3);
                if (!in[x][y][direc])
                {
                    in[x][y][direc]=true;
                    q[r=r==2000?1:r+1]=state(x,y,direc);
                }
            }
        }
        printf("%d\n",min(min(d[n][m][0],d[n][m][1]),min(d[n][m][2],d[n][m][3])));
    }
    return(0);
}

