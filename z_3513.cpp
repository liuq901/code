#include <cstdio>
#include <map>
using namespace std;
map <int,bool> f[40010];
bool dp(int x,int y)
{
    if (f[x].count(y))
        return(f[x][y]);
    if (x==0 || y==0)
        return(f[x][y]=true);
    if (x>y)
        return(f[x][y]=dp(y,x));
    bool flag=false;
    for (int i=y/x;i;i--)
        if (!dp(x,y-i*x))
        {
            flag=true;
            break;
        }
    return(f[x][y]=flag);
}
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                if (!f[i].count(j))
                    dp(i,j);
        static int id=0;
        printf("Case #%d:\n",++id);
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=m;j++)
                printf("%c",f[i][j]?'H':'P');
            printf("\n");
        }
    }
    return(0);
}

