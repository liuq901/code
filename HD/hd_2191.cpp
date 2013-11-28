#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        memset(f,0,sizeof(f));
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=m;i++)
        {
            int p,h,c;
            scanf("%d%d%d",&p,&h,&c);
            for (int j=1;j<=c;j++)
            {
                for (int k=n;k>=p;k--)
                    f[k]=max(f[k],f[k-p]+h);
            }
        }
        printf("%d\n",f[n]);
    }
    return(0);
}

