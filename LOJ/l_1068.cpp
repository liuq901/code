#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[40],f[40][110][110],g[40][110][110];
int calc(int x,int n)
{
    if (n>100)
        return(1);
    int len=0;
    while (x)
    {
        a[++len]=x%10;
        x/=10;
    }
    reverse(a+1,a+len+1);
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    g[0][0][0]=1;
    for (int i=1;i<=len;i++)
        for (int j=0;j<n;j++)
            for (int k=0;k<n;k++)
                for (int l=0;l<=9;l++)
                {
                    int u=(j+l)%n,v=(k*10+l)%n;
                    f[i][u][v]+=f[i-1][j][k];
                    if (l<a[i])
                        f[i][u][v]+=g[i-1][j][k];
                    if (l==a[i])
                        g[i][u][v]+=g[i-1][j][k];
                }
    return(f[len][0][0]+g[len][0][0]);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int L,R,m;
        scanf("%d%d%d",&L,&R,&m);
        static int id=0;
        printf("Case %d: %d\n",++id,calc(R,m)-calc(L-1,m));
    }
    return(0);
}

