#include <cstdio>
#include <algorithm>
using namespace std;
int X[1010],Y[1010],a[1000010];
inline int sqr(int x)
{
    return(x*x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d%d",&X[i],&Y[i]);
        int m=0;
        for (int i=1;i<=n;i++)
            for (int j=i+1;j<=n;j++)
                a[m++]=sqr(X[i]-X[j])+sqr(Y[i]-Y[j]);
        sort(a,a+m);
        m=unique(a,a+m)-a;
        static int id=0;
        printf("Case %d: %d\n",++id,m+1);
    }
    return(0);
}

