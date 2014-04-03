#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[210][110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++)
            for (int j=1;j<=i;j++)
            {
                int x;
                scanf("%d",&x);
                f[i][j]=max(f[i-1][j-1],f[i-1][j])+x;
            }
        int t=n;
        for (int i=n-1;i;i--)
        {
            t++;
            for (int j=1;j<=i;j++)
            {
                int x;
                scanf("%d",&x);
                f[t][j]=max(f[t-1][j],f[t-1][j+1])+x;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,f[2*n-1][1]);
    }
    return(0);
}

