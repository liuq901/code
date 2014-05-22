#include <cstdio>
#include <cstring>
typedef long long ll;
const int mod=1000000007;
int state[40],to[130],one[40][40];
void init()
{
    int m=0;
    for (int i=0;i<1<<7;i++)
        if (__builtin_popcount(i)==4)
        {
            to[i]=++m;
            state[m]=i;
        }
    for (int i=1;i<=m;i++)
    {
        for (int j=0;j<1<<4;j++)
        {
            int cnt=0;
            bool flag=true,a[7]={0};
            for (int k=0;k<7;k++)
                if (state[i]>>k&1)
                {
                    int now=j>>cnt&1;
                    cnt++;
                    int x=now?k-1:k+1;
                    if (x<0 || x>=7 || a[x])
                    {
                        flag=false;
                        break;
                    }
                    a[x]=true;
                }
            if (flag)
            {
                int now=0;
                for (int k=0;k<7;k++)
                    now|=a[k]<<k;
                one[i][to[now]]++;
            }
        }
    }
}
int ans[40][40];
void multiply(int a[][40],int b[][40],int c[][40])
{
    int d[40][40]={0};
    for (int i=1;i<=35;i++)
        for (int j=1;j<=35;j++)
            for (int k=1;k<=35;k++)
                d[i][j]=(d[i][j]+ll(a[i][k])*b[k][j])%mod;
    memcpy(c,d,sizeof(d));
}
void power(int n)
{
    int ret[40][40]={0};
    for (int i=1;i<=35;i++)
        ret[i][i]=1;
    int x[40][40];
    memcpy(x,one,sizeof(one));
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
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int state=0;
        for (int i=0;i<7;i++)
        {
            int x;
            scanf("%d",&x);
            if (x)
                state|=1<<i;
        }
        power(n-1);
        int x=to[state],sum=0;
        for (int i=1;i<=35;i++)
            sum=(sum+ans[x][i])%mod;
        static int id=0;
        printf("Case %d: %d\n",++id,sum);
    }
    return(0);
}

