#include <cstdio>
#include <cstring>
void multiply(int a[][6],int b[][6],int c[][6],int mod)
{
    int d[6][6]={0};
    for (int i=0;i<6;i++)
        for (int j=0;j<6;j++)
            for (int k=0;k<6;k++)
                d[i][j]=(d[i][j]+a[i][k]*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
int ans[6][6];
void power(int n,int a1,int b1,int c1,int a2,int b2,int c2,int mod)
{
    int ret[6][6]={0};
    for (int i=0;i<6;i++)
        ret[i][i]=1;
    int x[6][6]={0};
    x[1][0]=x[2][1]=x[4][3]=x[5][4]=1;
    x[2][2]=a1,x[1][2]=b1,x[3][2]=c1;
    x[5][5]=a2,x[4][5]=b2,x[0][5]=c2;
    for (;n;n>>=1)
    {
        if (n&1)
            multiply(ret,x,ret,mod);
        multiply(x,x,x,mod);
    }
    memcpy(ans,ret,sizeof(ret));
}
int calc(int a[],int id,int mod)
{
    int ret=0;
    for (int i=0;i<6;i++)
        ret=(ret+a[i]*ans[i][id])%mod;
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a1,b1,c1,a2,b2,c2,f0,f1,f2,g0,g1,g2,m;
        scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d",&a1,&b1,&c1,&a2,&b2,&c2,&f0,&f1,&f2,&g0,&g1,&g2,&m);
        a1%=m,b1%=m,c1%=m;
        a2%=m,b2%=m,c2%=m;
        f0%=m,f1%=m,f2%=m;
        g0%=m,g1%=m,g2%=m;
        int a[6]={f0,f1,f2,g0,g1,g2};
        static int id=0;
        printf("Case %d:\n",++id);
        int Q;
        scanf("%d",&Q);
        while (Q--)
        {
            int n;
            scanf("%d",&n);
            power(n,a1,b1,c1,a2,b2,c2,m);
            printf("%d %d\n",calc(a,0,m),calc(a,3,m));
        }
    }
    return(0);
}

