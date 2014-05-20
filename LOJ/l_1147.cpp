#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
bool f[110][100010];
int a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m=0;
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        f[0][0]=true;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
        {
            int x=a[i];
            m+=x;
            for (int j=i;j;j--)
                for (int k=x;k<=m;k++)
                    if (f[j-1][k-x])
                        f[j][k]=true;
        }
        int l=0,r=m;
        for (int i=0;i<=m;i++)
        {
            if (!f[n/2][i])
                continue;
            int x=i,y=m-i;
            if (x>y)
                swap(x,y);
            if (x>=l)
                l=x,r=y;
        }
        static int id=0;
        printf("Case %d: %d %d\n",++id,l,r);
    }
    return(0);
}

