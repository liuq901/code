#include <cstdio>
#include <cstring>
const int N=100,n=3;
int l,r,Sx,Sy,Sz,Tx,Ty,Tz,a[10][10],pre[N][N][N],f[N][N][N],q[1000000][3];
char way[N][N][N];
void print(int x,int y,int z)
{
    if (x==Sx && y==Sy && z==Sz)
        return;
    int t=pre[x][y][z];
    print(q[t][0],q[t][1],q[t][2]);
    printf("%c",way[x][y][z]);
}
bool machine(int from,int id,int value,int x,int y,int z)
{
    if (id==1)
        x--;
    if (id==2)
        y--;
    if (id==3)
        z--;
    if (x<0 || y<0 || z<0 || x>=N || y>=N || z>=N)
        return(false);
    x+=a[id][1],y+=a[id][2],z+=a[id][3];
    if (f[x][y][z]!=-1)
        return(false);
    f[x][y][z]=value+1;
    pre[x][y][z]=from;
    way[x][y][z]='A'+id-1;
    q[++r][0]=x,q[r][1]=y,q[r][2]=z;
    if (x==Tx && y==Ty && z==Tz)
    {
        printf("%d ",f[x][y][z]);
        print(Tx,Ty,Tz);
        printf("\n");
        return(true);
    }
    return(false);
}
bool rev_machine(int from,int id,int value,int x,int y,int z)
{
    x-=a[id][1],y-=a[id][2],z-=a[id][3];
    if (x<0 || y<0 || z<0 || x>=N || y>=N || z>=N)
        return(false);
    if (id==1)
        x++;
    if (id==2)
        y++;
    if (id==3)
        z++;
    if (f[x][y][z]!=-1)
        return(false);
    f[x][y][z]=value+1;
    pre[x][y][z]=from;
    way[x][y][z]='a'+id-1;
    q[++r][0]=x,q[r][1]=y,q[r][2]=z;
    if (x==Tx && y==Ty && z==Tz)
    {
        printf("%d ",f[x][y][z]);
        print(Tx,Ty,Tz);
        printf("\n");
        return(true);
    }
    return(false);
}
void bfs()
{
    if (Sx==Tx && Sy==Ty && Sz==Tz)
        printf("0\n");
    q[l=r=1][0]=Sx,q[1][1]=Sy,q[1][2]=Sz;
    memset(f,-1,sizeof(f));
    f[Sx][Sy][Sz]=0;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l][1],z0=q[l][2];
        for (int i=1;i<=3;i++)
        {
            if (machine(l,i,f[x0][y0][z0],x0,y0,z0))
                return;
            if (rev_machine(l,i,f[x0][y0][z0],x0,y0,z0))
                return;
        }
        l++;
    }
    printf("NO SOLUTION\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id,Q;
        scanf("%d%d",&id,&Q);
        printf("%d %d\n",id,Q);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        while (Q--)
        {
            scanf("%d%d%d%d%d%d%d",&id,&Sx,&Sy,&Sz,&Tx,&Ty,&Tz);
            printf("%d ",id);
            bfs();
        }
    }
    return(0);
}

