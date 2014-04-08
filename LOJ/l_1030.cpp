#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
double f[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for (int i=n;i;i--)
        {
            int t=min(n-i,6);
            f[i]=a[i];
            for (int j=i+1;j<=i+t;j++)
                f[i]+=f[j]/t;
        }
        static int id=0;
        printf("Case %d: %.10f\n",++id,f[1]);
    }
    return(0);
}

