#include <cstdio>
const int c[3][4][2]={{{-1,0},{1,0},{0,-1},{0,1}},{{-1,-1},{-1,1},{1,-1},{1,1}},{{0,-2},{0,2},{-2,0},{2,0}}};
int ans[20][2],a[20][20];
bool check(int x0,int y0)
{
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            if (i+2>x0 || i+2==x0 && j==y0)
                return(true);
            if (a[i][j]!=0)
                return(false);
        }
}
bool check(int x0,int y0,int kind)
{
    if (a[x0][y0]==0)
        return(false);
    for (int k=0;k<=kind;k++)
        for (int i=0;i<4;i++)
        {
            int x=x0+c[k][i][0],y=y0+c[k][i][1];
            if (x>=1 && x<=10 && y>=1 && y<=10 && a[x][y]==0)
                return(false);
        }
    return(true);
}
int save(int x0,int y0,int kind)
{
    int ret=1;
    a[x0][y0]--;
    for (int k=0;k<=kind;k++)
        for (int i=0;i<4;i++)
        {
            int x=x0+c[k][i][0],y=y0+c[k][i][1];
            if (x>=1 && x<=10 && y>=1 && y<=10)
            {
                ret++;
                a[x][y]--;
            }
        }
    return(ret);
}
int load(int x0,int y0,int kind)
{
    int ret=1;
    a[x0][y0]++;
    for (int k=0;k<=kind;k++)
        for (int i=0;i<4;i++)
        {
            int x=x0+c[k][i][0],y=y0+c[k][i][1];
            if (x>=1 && x<=10 && y>=1 && y<=10)
            {
                ret++;
                a[x][y]++;
            }
        }
    return(ret);
}
bool dfs(int dep,int x0,int y0,int sum)
{
    if (dep==0)
        return(sum==0);
    if (!check(x0,y0))
        return(false);
    for (int i=x0;i<=10;i++)
    {
        int p=i==x0?y0:1;
        for (int j=p;j<=10;j++)
            for (int k=0;k<=2;k++)
            {
                if (!check(i,j,k))
                    break;
                sum-=save(i,j,k);
                if (dfs(dep-1,i,j,sum))
                {
                    printf("%d %d %d\n",j-1,i-1,k+1);
                    return(true);
                }
                sum+=load(i,j,k);
            }
    }
    return(false);
}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for (int i=1;i<=10;i++)
        for (int j=1;j<=10;j++)
        {
            scanf("%d",&a[i][j]);
            sum+=a[i][j];
        }
    dfs(n,1,1,sum);
    return(0);
}

