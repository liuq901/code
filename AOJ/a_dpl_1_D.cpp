#include <cstdio>
#include <algorithm>
using namespace std;
int f[100010];
int main()
{
    int n,m;
    scanf("%d",&n);
    f[m=0]=-1;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        int p=lower_bound(f,f+m+1,x)-f;
        if (p==m+1)
            f[++m]=x;
        else
            f[p]=min(f[p],x);
    }
    printf("%d\n",m);
    return(0);
}

