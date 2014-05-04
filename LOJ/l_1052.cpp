#include <cstdio>
#include <cstring>
typedef long long ll;
 int mod=1000000007;
void multiply(int a[][2],int b[][2],int c[][2])
{
    int d[2][2]={0};
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                d[i][j]=(d[i][j]+ll(a[i][k])*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
int a[2][2];
int power(int y)
{
    int ret[2][2]={{1,0},{0,1}};
    int x[2][2]={{0,1},{1,1}};
    for (;y;y>>=1)
    {
        if (y&1)
            multiply(ret,x,ret);
        multiply(x,x,x);
    }
    memcpy(a,ret,sizeof(ret));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,X,m,Y,K;
        scanf("%d%d%d%d%d",&n,&X,&m,&Y,&K);
        static int id=0;
        printf("Case %d: ",++id);
        power(n-1);
        ll a1=a[0][0]+a[0][1],b1=a[1][0]+a[1][1];
        power(m-1);
        ll a2=a[0][0]+a[0][1],b2=a[1][0]+a[1][1];
        ll tmp=a1*b2-a2*b1;
        if (tmp==0 || (a2*X-a1*Y)%tmp!=0 || (b2*X-b1*Y)%tmp!=0)
        {
            printf("Impossible\n");
            continue;
        }
        int y=-(a2*X-a1*Y)/tmp;
        int x=(b2*X-b1*Y)/tmp;
        if (x<0 || y<0 || x+y<=0 || a1*x+b1*y!=X || a2*x+b2*y!=Y)
        {
            printf("Impossible\n");
            continue;
        }
        power(K-1);
        printf("%d\n",(ll(x)*(a[0][0]+a[0][1])+ll(y)*(a[1][0]+a[1][1]))%mod);
    }
    return(0);
}

