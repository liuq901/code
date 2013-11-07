#include <cstdio>
#include <numeric>
using namespace std;
typedef long long ll;
int n=50;
ll f[60];
int main()
{
    f[0]=1;
    for (int i=1;i<=n;i++)
        for (int j=2;j<=4;j++)
            for (int k=0;k<=i-j;k++)
                f[i]+=f[k];
    printf("%lld\n",accumulate(f,f+n+1,0LL));
    return(0);
}

