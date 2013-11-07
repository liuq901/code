#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[40][40];
int main()
{
    memset(a,63,sizeof(a));
    a[0][1]=0;
    int n,ans=1<<30;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        for (int j=1;j<=m;j++)
            while (1)
            {
                int x;
                scanf("%d",&x);
                if (x==0)
                    break;
                int y;
                scanf("%d",&y);
                a[i][j]=min(a[i][j],a[i-1][x]+y);
                if (i==n)
                    ans=min(ans,a[i][j]);
            }
        scanf("%*s");
    }
    printf("%d\n",ans);
    return(0);
}

