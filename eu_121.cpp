#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int n=15;
double f[20][20];
int main()
{
    f[0][0]=1;
    for (int i=1;i<=n;i++)
        for (int j=0;j<i;j++)
        {
            double red=f[i-1][j]*i/(i+1),blue=f[i-1][j]/(i+1);
            f[i][j]+=red;
            f[i][j+1]+=blue;
        }
    double ans=0;
    for (int i=0;i<=n;i++)
    {
        if (2*i<=n)
            continue;
        ans+=f[n][i];
    }
    printf("%d\n",int(1/ans));
    return(0);
}

