#include <cstdio>
#include <cstring>
const int mod=10007;
void multiply(int a[][4],int b[][4],int c[][4])
{
    int d[4][4]={0};
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++)
            for (int k=0;k<4;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
int ans[4][4];
void power(int n)
{
    int ret[4][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    int x[4][4]={{0,1,1,1},{0,0,1,1},{0,1,0,1},{1,0,0,1}};
    for (;n;n>>=1)
    {
        if (n&1)
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
        int n;
        scanf("%d",&n);
        power(n);
        static int id=0;
        printf("Case %d: %d\n",++id,ans[3][3]);
    }
    return(0);
}

