#include <cstdio>
#include <cstring>
const int c[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m,cnt,final;
char kind[20],a[20][20];
int pos[20][2],b[20][20],d[20][20],q[230][2],f[33000][20];
void bfs(int id)
{
    memset(d,-1,sizeof(d));
    int Sx=pos[id][0],Sy=pos[id][1];
    d[Sx][Sy]=0;
    int l,r;
    q[l=r=1][0]=Sx,q[1][1]=Sy;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<4;i++)
        {
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x>0 && x<=n && y>0 && y<=m && a[x][y]!='D' && d[x][y]==-1)
            {
                d[x][y]=d[x0][y0]+1;
                q[++r][0]=x,q[r][1]=y;
            }
        }
    }
    for (int i=1;i<=cnt;i++)
        b[id][i]=d[pos[i][0]][pos[i][1]];
}
void update(int &a,int b)
{
    if (a==-1 || b<a)
        a=b;
}
bool check(int mid)
{
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    for (int i=0;i<1<<cnt;i++)
        for (int j=0;j<=cnt;j++)
        {
            if (f[i][j]==-1)
                continue;
            if ((i&final)==final)
                return(true);
            for (int k=1;k<=cnt;k++)
            {
                if (i>>k-1&1 || b[j][k]==-1)
                    continue;
                int value=kind[j]=='G'?b[j][k]:f[i][j]+b[j][k];
                if (value<=mid)
                    update(f[i|1<<k-1][k],value);
            }
        }
    return(false);
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%s",a[i]+1);
        cnt=0,final=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                if (a[i][j]=='G' || a[i][j]=='Y')
                {
                    cnt++;
                    pos[cnt][0]=i;
                    pos[cnt][1]=j;
                    kind[cnt]=a[i][j];
                    if (a[i][j]=='Y')
                        final|=1<<cnt-1;
                }
                if (a[i][j]=='F')
                {
                    pos[0][0]=i;
                    pos[0][1]=j;
                    kind[0]='F';
                }
            }
        for (int i=0;i<=cnt;i++)
            bfs(i);
        int l=0,r=n*m,ans=-1;
        while (l<=r)
        {
            int mid=l+r>>1;
            if (check(mid))
                ans=mid,r=mid-1;
            else
                l=mid+1;
        }
        printf("%d\n",ans);
    }
    return(0);
}

