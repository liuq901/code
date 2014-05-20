#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int c[8][2]={{-1,2},{-1,-2},{-2,-1},{-2,1},{2,-1},{2,1},{1,2},{1,-2}};
char a[10][10],target[10][10];
void init()
{
    for (int i=1;i<=5;i++)
        target[1][i]='1';
    target[2][1]='0';
    for (int i=2;i<=5;i++)
        target[2][i]='1';
    for (int i=1;i<=2;i++)
    {
        target[3][i]='0';
        target[3][i+3]='1';
    }
    target[3][3]='2';
    for (int i=1;i<=4;i++)
        target[4][i]='0';
    target[4][5]='1';
    for (int i=1;i<=5;i++)
        target[5][i]='0';
}
int best()
{
    int ret=0;
    for (int i=1;i<=5;i++)
        for (int j=1;j<=5;j++)
            ret+=a[i][j]!='2' && a[i][j]!=target[i][j];
    return(ret);
}
int ans;
bool dfs(int dep,int x0,int y0,int pre)
{
    int p=best();
    if (p==0)
        return(true);
    if (dep+p>ans)
        return(false);
    for (int i=0;i<8;i++)
    {
        int x=x0+c[i][0],y=y0+c[i][1];
        if (x<=0 || x>5 || y<=0 || y>5 || i==pre)
            continue;
        swap(a[x0][y0],a[x][y]);
        if (dfs(dep+1,x,y,7-i))
            return(true);
        swap(a[x0][y0],a[x][y]);
    }
    return(false);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    gets(a[0]);
    while (T--)
    {
        for (int i=1;i<=5;i++)
            gets(a[i]+1);
        int Sx,Sy;
        for (int i=1;i<=5;i++)
            for (int j=1;j<=5;j++)
                if (a[i][j]==' ')
                {
                    a[i][j]='2';
                    Sx=i,Sy=j;
                }
        bool flag=false;
        static int id=0;
        printf("Case %d: ",++id);
        for (ans=best();ans<=15;ans++)
            if (dfs(0,Sx,Sy,-1))
            {
                printf("Solvable in %d move(s).\n",ans);
                flag=true;
                break;
            }
        if (!flag)
            printf("Unsolvable in less than 16 move(s).\n");
    }
    return(0);
}

