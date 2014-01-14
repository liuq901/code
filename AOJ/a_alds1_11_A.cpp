#include <cstdio>
bool f[110][110];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int id,K;
        scanf("%d%d",&id,&K);
        for (int j=1;j<=K;j++)
        {
            int x;
            scanf("%d",&x);
            f[id][x]=true;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            printf("%d%c",f[i][j],j==n?'\n':' ');
    return(0);
}

