#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[10000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n=0;
        while (1)
        {
            int x;
            scanf("%d",&x);
            if (x==0)
                break;
            a[++n]=x;
        }
        sort(a+1,a+n+1,greater <int>());
        int limit=2500000;
        for (int i=1;i<=n;i++)
        {
            int now=1;
            for (int j=1;j<=i;j++)
            {
                if (ll(now)*a[i]>limit)
                {
                    limit=-1;
                    break;
                }
                now*=a[i];
            }
            if (limit==-1)
                break;
            limit-=now;
        }
        if (limit==-1)
            printf("Too expensive\n");
        else
            printf("%d\n",(2500000-limit)*2);
    }
    return(0);
}

