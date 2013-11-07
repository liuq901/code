#include <cstdio>
#include <cstring>
const int c[8][2]={{-1,0},{1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
char a[2010][2010];
int n,v,ans1,ans2;
int check()
{
    int sum=0,tot=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            sum+=a[i][j]=='X';
            tot+=a[i][j]=='O';
        }
    if (sum==tot)
        return(1);
    if (sum==tot+1)
        return(-1);
    return(0);
}
int b[2010][2010],f[4][2010][2010],q[4000010][2];
bool vis[2010][2010];
void bfs(int Sx,int Sy,int op)
{
    memset(vis,0,sizeof(vis));
    vis[Sx][Sy]=true;
    int l=1,r=1;
    q[1][0]=Sx,q[1][1]=Sy;
    while (l<=r)
    {
        int x0=q[l][0],y0=q[l++][1];
        for (int i=0;i<8;i++)
        {
            if (op!=-1 && i!=op)
                continue;
            int x=x0+c[i][0],y=y0+c[i][1];
            if (x<=0 || x>n || y<=0 || y>n || !b[x][y] || vis[x][y])
                continue;
            vis[x][y]=true;
            q[++r][0]=x,q[r][1]=y;
        }
    }
}
bool win(bool first)
{
    int sum=0,tot=0,&ret=first?ans1:ans2,x0,y0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (b[i][j]>0)
                sum++;
            if (b[i][j]>1)
            {
                tot++;
                x0=i,y0=j;
            }
        }
    if (sum==0)
    {
        ret=0;
        return(true);
    }
    if (tot>1)
    {
        ret=2;
        return(false);
    }
    if (tot==1)
        for (int i=0;i<8;i++)
        {
            int x=x0,y=y0;
            bool flag=true;
            for (int j=1;j<=v;j++)
            {
                x+=c[i][0],y+=c[i][1];
                if (x<=0 || x>n || y<=0 || y>n || !b[x][y])
                {
                    flag=false;
                    break;
                }
            }
            if (flag)
            {
                ret=2;
                return(false);
            }
        }
    if (tot==1)
        bfs(x0,y0,-1);
    else
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (b[i][j])
                {
                    int k;
                    for (int p=0;p<8;p++)
                    {
                        int x=i+c[p][0],y=j+c[p][1];
                        if (x<=0 || x>n || y<=0 || y>n || !b[x][y])
                            continue;
                        k=p;
                        break;
                    }
                    bfs(i,j,k);
                    goto out;
                }
    }
out:
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (b[i][j] && !vis[i][j])
            {
                ret=2;
                return(false);
            }
    ret=1;
    return(true);
}
void dp()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]=='.')
                continue;
            f[0][i][j]=i==1 || a[i-1][j]!=a[i][j]?1:f[0][i-1][j]+1;
            f[1][i][j]=j==1 || a[i][j-1]!=a[i][j]?1:f[1][i][j-1]+1;
            f[2][i][j]=i==1 || j==1 || a[i-1][j-1]!=a[i][j]?1:f[2][i-1][j-1]+1;
            f[3][i][j]=i==1 || j==n || a[i-1][j+1]!=a[i][j]?1:f[3][i-1][j+1]+1;
            for (int k=0;k<4;k++)
                if (f[k][i][j]>=2*v)
                {
                    ans1=ans2=1;
                    return;
                }
        }
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]!='X')
                continue;
            if ((i==n || a[i][j]!=a[i+1][j]) && f[0][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (i-k<=0 || a[i-k][j]!='X')
                        break;
                    b[i-k][j]++;
                }
            if ((j==n || a[i][j]!=a[i][j+1]) && f[1][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (j-k<=0 || a[i][j-k]!='X')
                        break;
                    b[i][j-k]++;
                }
            if ((i==n || j==n || a[i][j]!=a[i+1][j+1]) && f[2][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (i-k<=0 || j-k<=0 || a[i-k][j-k]!='X')
                        break;
                    b[i-k][j-k]++;
                }
            if ((i==n || j==1 || a[i][j]!=a[i+1][j-1]) && f[3][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (i-k<=0 || j+k>n || a[i-k][j+k]!='X')
                        break;
                    b[i-k][j+k]++;
                }
        }
    if (!win(true))
        return;
    memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            if (a[i][j]!='O')
                continue;
            if ((i==n || a[i][j]!=a[i+1][j]) && f[0][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (i-k<=0 || a[i-k][j]!='O')
                        break;
                    b[i-k][j]++;
                }
            if ((j==n || a[i][j]!=a[i][j+1]) && f[1][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (j-k<=0 || a[i][j-k]!='O')
                        break;
                    b[i][j-k]++;
                }
            if ((i==n || j==n || a[i][j]!=a[i+1][j+1]) && f[2][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (i-k<=0 || j-k<=0 || a[i-k][j-k]!='O')
                        break;
                    b[i-k][j-k]++;
                }
            if ((i==n || j==1 || a[i][j]!=a[i+1][j-1]) && f[3][i][j]>=v)
                for (int k=0;;k++)
                {
                    if (i-k<=0 || j+k>n || a[i-k][j+k]!='O')
                        break;
                    b[i-k][j+k]++;
                }
        }
    win(false);
}
bool all()
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]=='.')
                return(false);
    return(true);
}
void work()
{
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
    int p=check();
    if (p==0)
        printf("ERROR\n");
    else
    {
        dp();
        if (ans1+ans2>1)
            printf("ERROR\n");
        else if (ans1==1)
            printf("%s\n",p==-1?"X WINS":"ERROR");
        else if (ans2==1)
            printf("%s\n",p==1?"O WINS":"ERROR");
        else
            printf("%s\n",all()?"DRAW":"IN PROGRESS");
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
        work();
    return(0);
}

