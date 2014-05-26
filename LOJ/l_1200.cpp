#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[110],b[110],f[10010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d%d%d",&a[i],&x,&b[i]);
            m-=x*b[i];
        }
        static int id=0;
        printf("Case %d: ",++id);
        if (m<0)
            printf("Impossible\n");
        else
        {
            memset(f,0,sizeof(f));
            for (int i=1;i<=n;i++)
                for (int j=b[i];j<=m;j++)
                    f[j]=max(f[j],f[j-b[i]]+a[i]);
            printf("%d\n",f[m]);
        }
    }
    return(0);
}

