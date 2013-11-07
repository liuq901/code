#include <cstdio>
#include <bitset>
using namespace std;
bitset <240> a[240];
int main()
{
    while (1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if (n==0 && m==0)
            break;
        for (int i=1;i<=n;i++)
        {
            a[i].reset();
            a[i].set(i);
        }
        int ans=0;
        for (int i=1;i<=m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if (a[y][x])
                ans++;
            else
                for (int j=1;j<=n;j++)
                    if (a[j][x])
                        a[j]|=a[y];
        }
        static int id=0;
        printf("%d. %d\n",++id,ans);
    }
    return(0);
}

