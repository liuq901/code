#include <cstdio>
#include <algorithm>
using namespace std;
int Log[100010],f[17][100010];
void init()
{
    Log[1]=0;
    for (int i=2;i<=100000;i++)
    {
        Log[i]=Log[i-1];
        if (i&i-1)
            continue;
        Log[i]++;
    }
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,Q;
        scanf("%d%d",&n,&Q);
        for (int i=1;i<=n;i++)
            scanf("%d",&f[0][i]);
        for (int i=1;i<=Log[n];i++)
            for (int j=1;j<=n;j++)
            {
                if (j+(1<<i)-1>n)
                    break;
                f[i][j]=min(f[i-1][j],f[i-1][j+(1<<i-1)]);
            }
        static int id=0;
        printf("Case %d:\n",++id);
        while (Q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int t=Log[r-l+1];
            printf("%d\n",min(f[t][l],f[t][r-(1<<t)+1]));
        }
    }
    return(0);
}

