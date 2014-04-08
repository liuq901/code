#include <cstdio>
#include <algorithm>
using namespace std;
int s[110],f[110][110],g[110][110];
inline int get(int x,int y)
{
    return(s[y]-s[x-1]);
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
        {
            int x;
            scanf("%d",&x);
            s[i]=s[i-1]+x;
        }
        for (int i=n;i;i--)
            for (int j=i;j<=n;j++)
            {
                f[i][j]=get(i,j);
                g[i][j]=-get(i,j);
                for (int k=i;k<=j;k++)
                {
                    if (i<k)
                    {
                        f[i][j]=max(f[i][j],g[k][j]+get(i,k-1));
                        g[i][j]=min(g[i][j],f[k][j]-get(i,k-1));
                    }
                    if (k<j)
                    {
                        f[i][j]=max(f[i][j],g[i][k]+get(k+1,j));
                        g[i][j]=min(g[i][j],f[i][k]-get(k+1,j));
                    }
                }
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[1][n]);
    }
    return(0);
}

