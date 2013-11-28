#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll f[30][210];
inline ll calc(int x,int a,int b)
{
    ll ret=1;
    for (int i=1;i<=b;i++)
        ret*=x;
    return(ret*a);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    memset(f,63,sizeof(f));
    f[0][0]=0;
    for (int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for (int j=0;j<=n;j++)
            for (int k=0;k<=j;k++)
                f[i][j]=min(f[i][j],f[i-1][k]+calc(j-k,x,y));
    }
    printf("%I64d\n",f[m][n]);
    return(0);
}

