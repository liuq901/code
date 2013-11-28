#include <cstdio>
#include <cstring>
using namespace std;
const int c[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char a[1010][1010];
int n,m,d[1010][1010],q[2][1000010][2];
bool in[1010][1010];
int spfa(int Sx,int Sy,int Tx,int Ty)
{
    if (Sx==Tx && Sy==Ty)
        return(0);
    memset(d,-1,sizeof(d));
    d[Sx][Sy]=0;
    int l[2],r[2];
    l[0]=r[0]=1;
    l[1]=1,r[1]=0;
    q[0][1][0]=Sx,q[0][1][1]=Sy;
    int u=0;
    while (1)
    {
        while (l[u]<=r[u])
        {
            int x0=q[u][l[u]][0],y0=q[u][l[u]++][1];
            int t=a[x0][y0]-'0';
            int x=x0+c[t][0],y=y0+c[t][1];
            if (x==0 || x>n || y==0 || y>m || d[x][y]!=-1)
                continue;
            d[x][y]=d[x0][y0];
            q[u][++r[u]][0]=x,q[u][r[u]][1]=y;
            if (x==Tx && y==Ty)
                return(d[x][y]);
        }
        for (int i=1;i<=r[u];i++)
        {
            int x0=q[u][i][0],y0=q[u][i][1];
            for (int i=0;i<8;i++)
            {
                int x=x0+c[i][0],y=y0+c[i][1];
                if (x==0 || x>n || y==0 || y>m || d[x][y]!=-1)
                    continue;
                d[x][y]=d[x0][y0]+1;
                q[u^1][++r[u^1]][0]=x,q[u^1][r[u^1]][1]=y;
                if (x==Tx && y==Ty)
                    return(d[x][y]);
            }
        }        
        l[u]=1,r[u]=0;
        u^=1;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int Sx,Sy,Tx,Ty;
        scanf("%d%d%d%d",&Sx,&Sy,&Tx,&Ty);
        printf("%d\n",spfa(Sx,Sy,Tx,Ty));
    }
    return(0);
}

