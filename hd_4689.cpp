#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;
pair <int,char> a[30];
char buf[10000];
int s[30];
ll fac[30],f[30][30];
int main()
{
    fac[0]=1;
    for (int i=1;i<=20;i++)
        fac[i]=fac[i-1]*i;
    while (scanf("%s",buf)==1)
    {
        int n=strlen(buf),m=0;
        for (int i=1;i<=n;i++)
            if (buf[i-1]=='-')
                a[i]=make_pair(i-1,'-');
            else
            {
                a[i]=make_pair(i,'+');
                m++;
            }
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
            s[i]=s[i-1]+(a[i].second=='-');
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=1;i<=n;i++)
            for (int j=0;j<i;j++)
            {
                if (f[i-1][j]==0)
                    continue;
                if (a[i].second=='-')
                    f[i][j]+=f[i-1][j]*max(0,a[i].first-(j+s[i]-1));
                else
                {
                    f[i][j]+=f[i-1][j];
                    f[i][j+1]+=f[i-1][j]*max(0,a[i].first-(j+s[i]));
                }
            }
        ll ans=0;
        int k=1;
        for (int i=0;i<=m;i++)
        {
            ans+=f[n][i]*k*fac[m-i];
            k*=-1;
        }
        printf("%I64d\n",ans);
    }
    return(0);
}

