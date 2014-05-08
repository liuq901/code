#include <cstdio>
#include <cstring>
int mod,ans[2][2];
void multiply(int a[][2],int b[][2],int c[][2])
{
    int d[2][2]={0};
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
void power(int y)
{
    int ret[2][2]={{1,0},{0,1}};
    int x[2][2]={{0,1},{1,1}};
    for (;y;y>>=1)
    {
        if (y&1)
            multiply(ret,x,ret);
        multiply(x,x,x);
    }
    memcpy(ans,ret,sizeof(ret));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,n,m;
        scanf("%d%d%d%d",&a,&b,&n,&m);
        mod=1;
        for (int i=1;i<=m;i++)
            mod*=10;
        power(n);
        static int id=0;
        printf("Case %d: %d\n",++id,(a*ans[0][0]+b*ans[1][0])%mod);
    }
    return(0);
}

