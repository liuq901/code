#include <cstdio>
#include <algorithm>
using namespace std;
int f[10010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        for (int j=m;j>=y;j--)
            f[j]=max(f[j],f[j-y]+x);
    }
    printf("%d\n",f[m]);
    return(0);
}

