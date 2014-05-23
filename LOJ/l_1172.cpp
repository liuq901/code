#include <cstdio>
#include <cstring>
unsigned N,a[260],one[260][260];
int sqr(int x)
{
    return(x*x);
}
void init(int base)
{
    memset(one,0,sizeof(one));
    int m=sqr(base-1);
    for (int i=1;i<m;i++)
        for (int j=0;j<base;j++)
            one[i*base+j][(i-1)*base+j]=1;
    N=m*base;
    unsigned f[30][10]={0};
    for (int i=1;i<base;i++)
        f[0][i]=1;
    for (int i=0;i<m;i++)
        for (int j=0;j<base;j++)
            for (int k=0;k<base;k++)
            {
                if (j==k)
                    continue;
                int add=i+sqr(j-k);
                if (add<m)
                    f[add][k]+=f[i][j];
                else if (add==m)
                    one[i*base+j][(add-1)*base+k]++;
            }
    for (int i=0;i<m;i++)
        for (int j=0;j<base;j++)
            a[i*base+j]=f[i][j];
}
void multiply(unsigned a[][260],unsigned b[][260],unsigned c[][260])
{
    unsigned d[260][260]={0};
    for (int i=0;i<N;i++)
        for (int k=0;k<N;k++)
        {
            if (!a[i][k])
                continue;
            for (int j=0;j<N;j++)
                d[i][j]+=a[i][k]*b[k][j];
        }
    memcpy(c,d,sizeof(d));
}
unsigned ans[260][260];
void power(int n)
{
    unsigned ret[260][260]={0};
    for (int i=0;i<N;i++)
        ret[i][i]=1;
    for (;n;n>>=1)
    {
        if (n&1)
            multiply(ret,one,ret);
        multiply(one,one,one);
    }
    memcpy(ans,ret,sizeof(ret));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        init(m);
        power(n);
        unsigned sum=0;
        for (int i=0;i<N;i++)
            for (int j=0;j<m;j++)
                sum+=a[i]*ans[i][j];
        static int id=0;
        printf("Case %d: %u\n",++id,sum);
    }
    return(0);
}

