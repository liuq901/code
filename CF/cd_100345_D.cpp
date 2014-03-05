#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
FILE *in,*out;
typedef long long ll;
const int limit=59049;
ll f[60000][20],g[60000][20];
int b[10];
ll calc(ll N)
{
    if (N==0)
        return(0);
    b[0]=1;
    for (int i=1;i<10;i++)
        b[i]=b[i-1]*3;
    int n=0,a[20];
    while (N)
    {
        a[++n]=N%10;
        N/=10;
    }
    reverse(a+1,a+n+1);
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    g[0][0]=1;
    for (int i=1;i<n;i++)
        f[0][i]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=9;j++)
            for (int k=0;k<limit;k++)
            {
                if (j==0 && k==0 || k/b[j]%3==2)
                    continue;
                f[k+b[j]][i]+=f[k][i-1];
                if (j<a[i])
                    f[k+b[j]][i]+=g[k][i-1];
                else if (j==a[i])
                    g[k+b[j]][i]+=g[k][i-1];
            }
    ll ans=0;
    for (int i=0;i<limit;i++)
        ans+=f[i][n]+g[i][n];
    return(ans);
}
int main()
{
    in=fopen("exchange.in","r");
    out=fopen("exchange.out","w");
    ll l,r;
    fscanf(in,"%I64d%I64d",&l,&r);
    fprintf(out,"%I64d\n",calc(r)-calc(l-1));
    return(0);
}

