#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1000010,mod=1000000007;
int a[10],sum[10],p[10],two[10],c[N],state[N],X[N],Y[N],b[N][8];
int power(int n)
{
    if (n==0)
        return(1);
    ll x=power(n>>1);
    x*=x;
    if (n&1)
        x<<=1;
    return(x%mod);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
        {
            printf("0\n");
            continue;
        }
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        a[0]=a[1]=X[1],a[2]=a[3]=Y[1],a[4]=a[5]=X[1]+Y[1],a[6]=a[7]=X[1]-Y[1];
        for (int i=1;i<=n;i++)
        {
            a[0]=max(a[0],X[i]),a[1]=min(a[1],X[i]);
            a[2]=max(a[2],Y[i]),a[3]=min(a[3],Y[i]);
            a[4]=max(a[4],X[i]+Y[i]),a[5]=min(a[5],X[i]+Y[i]);
            a[6]=max(a[6],X[i]-Y[i]),a[7]=min(a[7],X[i]-Y[i]);
            b[i][0]=b[i][1]=X[i];
            b[i][2]=b[i][3]=Y[i];
            b[i][4]=b[i][5]=X[i]+Y[i];
            b[i][6]=b[i][7]=X[i]-Y[i];
        }
        for (int i=1;i<=n;i++)
        {
            state[i]=0;
            c[i]=-1;
            for (int j=0;j<8;j++)
                if (b[i][j]==a[j])
                {
                    state[i]|=1<<j;
                    c[i]=j;
                }
        }
        int m=0,tot=0;
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=n;i++)
        {
            if (c[i]==-1)
            {
                tot++;
                continue;
            }
            if (1<<c[i]==state[i])
                sum[c[i]]++;
            else
                p[m++]=i;
        }
        tot=power(tot);
        for (int i=0;i<8;i++)
            two[i]=power(sum[i]);
        int ans=0;
        for (int i=0;i<1<<m;i++)
        {
            int now=0,x=tot;
            for (int j=0;j<m;j++)
                if (i>>j&1)
                    now|=state[p[j]];
            for (int j=0;j<8;j++)
            {
                int y;
                if (now>>j&1)
                    y=two[j];
                else
                    y=two[j]-1;
                if (y<0)
                    y+=mod;
                x=ll(x)*y%mod;
            }
            ans=(ans+x)%mod;
        }
        printf("%d\n",ans);
    }
    return(0);
}

