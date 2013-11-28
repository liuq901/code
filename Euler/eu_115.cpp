#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;
typedef long long ll;
const int m=50;
ll f[1000000];
int main()
{
    ll sum=1;
    for (int i=m;;i++)
    {
        f[i]=i-m+1;
        for (int j=m;j<=i;j++)
            for (int k=1;k<=i-j-1;k++)
                f[i]+=f[k];
        sum+=f[i];
        if (sum>=1000000)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

