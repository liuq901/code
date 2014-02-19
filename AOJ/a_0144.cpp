#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    memset(a,63,sizeof(a));
    for (int i=1;i<=n;i++)
    {
        int x,K;
        scanf("%d%d",&x,&K);
        for (int j=1;j<=K;j++)
        {
            int y;
            scanf("%d",&y);
            a[x][y]=1;
        }
    }
    for (int k=1;k<=n;k++)
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (z<=a[x][y])
            printf("NA\n");
        else
            printf("%d\n",a[x][y]+1);
    }
    return(0);
}

