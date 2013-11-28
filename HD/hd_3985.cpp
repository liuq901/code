#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int p[110][110],f[110][40010];
vector <int> a;
int get(int x)
{
    return(lower_bound(a.begin(),a.end(),x)-a.begin());
}
int main()
{
    for (int i=0;i<=100;i++)
    {
        p[i][0]=1;
        for (int j=1;j<=i;j++)
            p[i][j]=ll(p[i][j-1])*(i-j+1)%mod;
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,K;
        scanf("%d%d",&n,&K);
        a.clear();
        for (int i=1;i*i<=K;i++)
            if (K%i==0)
            {
                a.push_back(i);
                a.push_back(K/i);
            }
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        vector <int> b;
        for (int i=0;i<a.size();i++)
            if (a[i]<=n)
                b.push_back(a[i]);
        memset(f,0,sizeof(f));
        f[0][get(1)]=1;
        for (int i=0;i<n;i++)
            for (int j=0;j<a.size();j++)
            {
                if (f[i][j]==0)
                    continue;
                for (int id=0;id<b.size();id++)
                {
                    int k=b[id];
                    if (i+k>n)
                        break;
                    int now=p[n-(i+1)][k-1];
                    int lcm=a[j]/__gcd(a[j],k)*k;
                    f[i+k][get(lcm)]=(f[i+k][get(lcm)]+ll(f[i][j])*now)%mod;
                }
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][get(K)]);
    }
    return(0);
}

