#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[50010];
int main()
{
    int m,n;
    scanf("%d%d",&m,&n);
    memset(f,63,sizeof(f));
    f[0]=0;
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        for (int j=x;j<=m;j++)
            f[j]=min(f[j],f[j-x]+1);
    }
    printf("%d\n",f[m]);
    return(0);
}

