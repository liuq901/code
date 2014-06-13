#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int X,Y,Z,f[1010][2];
int dp(int n,int t)
{
    if (n==1)
        return(t?-X/2:0);
    if (f[n][t]!=-1)
        return(f[n][t]);
    int &ret=f[n][t];
    ret=1<<30;
    for (int i=1;i<n;i++)
        ret=min(ret,max(dp(i,0),dp(n-i,1)));
    ret+=t?Z:X+Y;
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d%d%d%d",&n,&X,&Y,&Z);
        memset(f,-1,sizeof(f));
        static int id=0;
        printf("Case %d: %d\n",++id,dp(n,0));
    }
    return(0);
}

