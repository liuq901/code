#include <cstdio>
#include <algorithm>
using namespace std;
int m,p[100010];
bool f[100010];
void init()
{
    int n=100000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=n;i++)
        if (!f[i])
            p[m++]=i;
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
        printf("%d %d\n",*(lower_bound(p,p+m,n)-1),*upper_bound(p,p+m,n));
    return(0);
}

