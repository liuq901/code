#include <cstdio>
#include <algorithm>
using namespace std;
int a[30][3],f[30][3];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=0;j<3;j++)
                scanf("%d",&a[i][j]);
        for (int i=1;i<=n;i++)
            for (int j=0;j<3;j++)
            {
                int x=j==0?1:0,y=3-j-x;
                f[i][j]=min(f[i-1][x],f[i-1][y])+a[i][j];
            }
        static int id=0;
        printf("Case %d: %d\n",++id,min(min(f[n][0],f[n][1]),f[n][2]));
    }
    return(0);
}

