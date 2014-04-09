#include <cstdio>
#include <cmath>
double a[1000010];
void init()
{
    const int n=1000000;
    for (int i=1;i<=n;i++)
        a[i]=a[i-1]+log(double(i));
    a[0]=1;
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        static int id=0;
        printf("Case %d: %.0f\n",++id,ceil(a[n]/log(double(m))));
    }
    return(0);
}

