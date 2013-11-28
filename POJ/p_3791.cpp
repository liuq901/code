#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;
double a[30],f[30][30][30];
int pre[30][30][30];
string print(int x,int y,int z)
{
    if (x==0 && y==0 && z==0)
        return("");
    if (z==1)
        return(print(x-1,y-1,pre[x][y][z])+" "+char(x+'A'-1));
    return(print(x-1,y,z-1)+char(x+'A'-1));
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=26;i++)
            scanf("%lf",&a[i]);
        for (int i=0;i<=26;i++)
            for (int j=0;j<=26;j++)
                for (int k=0;k<=26;k++)
                    f[i][j][k]=1e10;
        f[1][1][1]=a[1];
        pre[1][1][1]=0;
        for (int i=1;i<26;i++)
            for (int j=1;j<=n;j++)
                for (int k=0;k<=8;k++)
                {
                    if (f[i][j][k]>1e8)
                        continue;
                    if (f[i][j][k]+a[i+1]*(k+1)<f[i+1][j][k+1])
                        f[i+1][j][k+1]=f[i][j][k]+a[i+1]*(k+1);
                    if (j<n && f[i][j][k]+a[i+1]<f[i+1][j+1][1])
                    {
                        f[i+1][j+1][1]=f[i][j][k]+a[i+1];
                        pre[i+1][j+1][1]=k;
                    }
                }
        double ans=1e10;
        int k;
        for (int i=0;i<=8;i++)
            if (f[26][n][i]<ans)
            {
                ans=f[26][n][i];
                k=i;
            }
        static int id=0;
        printf("%d %.3f%s\n",++id,ans/100,print(26,n,k).c_str());
    }
    return(0);
}

