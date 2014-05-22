#include <cstdio>
#include <algorithm>
using namespace std;
int a[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int sum=0;
        for (int i=1;i<=n;i++)
        {
            int k;
            for (int j=1;j<=n;j++)
                if (a[j]==i)
                {
                    k=j;
                    break;
                }
            if (k!=i)
            {
                swap(a[k],a[i]);
                sum++;
            }
        }
        static int id=0;
        printf("Case %d: %d\n",++id,sum);
    }
    return(0);
}

