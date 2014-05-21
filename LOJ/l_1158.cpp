#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[20];
int f[1100][1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int m;
        scanf("%s%d",a,&m);
        int n=strlen(a);
        sort(a,a+n);
        memset(f,0,sizeof(f));
        f[0][0]=1;
        for (int i=0;i<1<<n;i++)
            for (int j=0;j<m;j++)
            {
                if (f[i][j]==0)
                    continue;
                for (int k=0;k<n;k++)
                {
                    if (i>>k&1 || k>0 && a[k]==a[k-1] && !(i>>k-1&1))
                        continue;
                    f[i|1<<k][(j*10+a[k]-'0')%m]+=f[i][j];
                }
            }
        static int id=0;
        printf("Case %d: %d\n",++id,f[(1<<n)-1][0]);
    }
    return(0);
}

