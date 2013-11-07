#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
double f[2][210][210];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id,n;
        double l,r;
        scanf("%d%d%lf%lf",&id,&n,&l,&r);
        memset(f,0,sizeof(f));
        f[0][100][100]=1;
        for (int i=0;i<n;i++)
        {
            memset(f[i+1&1],0,sizeof(f[i+1&1]));
            for (int j=100-i;j<=100+i;j++)
                for (int k=j;k<=100+i;k++)
                {
                    f[i+1&1][j-1][max(k,j-1)]+=f[i&1][j][k]*l;
                    f[i+1&1][j][max(k,j)]+=f[i&1][j][k]*(1-l-r);
                    f[i+1&1][j+1][max(k,j+1)]+=f[i&1][j][k]*r;
                }
        }
        double ans=0;
        for (int i=100-n;i<=100+n;i++)
            for (int j=i;j<=100+n;j++)
                ans+=f[n&1][i][j]*(j-100);
        printf("%d %.4f\n",id,ans);
    }
    return(0);
}

