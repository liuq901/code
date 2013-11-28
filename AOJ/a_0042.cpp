#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[1010];
int main()
{
    while (1)
    {
        int m;
        scanf("%d",&m);
        if (m==0)
            break;
        memset(f,-63,sizeof(f));
        f[0]=0;
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d,%d",&x,&y);
            for (int j=m;j>=y;j--)
                f[j]=max(f[j],f[j-y]+x);
        }
        static int id=0;
        int pos=max_element(f,f+m+1)-f;
        printf("Case %d:\n%d\n%d\n",++id,f[pos],pos);
    }
    return(0);
}

