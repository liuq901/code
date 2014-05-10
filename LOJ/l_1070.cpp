#include <cstdio>
#include <cstring>
typedef unsigned long long ull;
void multiply(ull a[][2],ull b[][2],ull c[][2])
{
    ull d[2][2]={0};
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                d[i][j]+=a[i][k]*b[k][j];
    memcpy(c,d,sizeof(d));
}
ull ans[2][2];
void power(ull p,ull q,ull n)
{
    ull ret[2][2]={{1,0},{0,1}};
    ull x[2][2]={{0,-q},{1,p}};
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
        ull p,q,n;
        scanf("%llu%llu%llu",&p,&q,&n);
        power(p,q,n);
        static int id=0;
        printf("Case %d: %llu\n",++id,2*ans[0][0]+p*ans[1][0]);
    }
    return(0);
}

