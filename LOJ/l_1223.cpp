#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[110][110][110];
int dp(int x,int y,int z)
{
    if (f[x][y][z]!=-1)
        return(f[x][y][z]);
    int &ret=f[x][y][z];
    if (y==z)
        ret=0;
    else if (x==0)
        ret=1<<30;
    else
    {
        ret=1<<30;
        for (int i=y+1;i<=z;i++)
            ret=min(ret,max(dp(x-1,y,i-1),dp(x,i,z))+i);
    }
    return(ret);
}
int main()
{
    memset(f,-1,sizeof(f));
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        static int id=0;
        printf("Case %d: %d\n",++id,dp(m,0,n));
    }
    return(0);
}

