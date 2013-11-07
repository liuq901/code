#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
int n=50;
ll f[60];
int main()
{
    f[0]=1;
    for (int i=3;i<=n;i++)
        f[i]=i-2;
    for (int i=1;i<=n;i++)
        for (int j=3;j<=i;j++)
            for (int k=1;k<=i-j-1;k++)
                f[i]+=f[k];
    printf("%lld\n",accumulate(f,f+n+1,0LL));
    return(0);
}

