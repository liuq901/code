#include <cstdio>
#include <algorithm>
using namespace std;
int f[1100][1100];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
            {
                scanf("%d",&f[i][j]);
                if (i==1)
                    f[i][j]+=f[i][j-1];
                else if (j==1)
                    f[i][j]+=f[i-1][j];
                else
                    f[i][j]+=max(f[i-1][j],f[i][j-1]);
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[n][m]);
    }
    return(0);
}

