#include <cstdio>
#include <queue>
using namespace std;
queue <int> Q;
int f[1100],a[110][20];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
        for (int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    f[(1<<n)-1]=1;
    Q.push((1<<n)-1);
    while (!Q.empty())
    {
        int x=Q.front();
        Q.pop();
        for (int i=1;i<=m;i++)
        {
            int y=x;
            for (int j=1;j<=n;j++)
            {
                if (a[i][j]==1)
                    y&=~(1<<j-1);
                if (a[i][j]==-1)
                    y|=1<<j-1;
            }
            if (f[y]==0)
            {
                f[y]=f[x]+1;
                Q.push(y);
            }
        }
    }
    if (f[0]==0)
        printf("The patient will be dead.\n");
    else
        printf("%d\n",f[0]-1);
    return(0);
}

