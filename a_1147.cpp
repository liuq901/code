#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        int mi=10000,ma=-1,sum=0;
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
            mi=min(mi,x);
            ma=max(ma,x);
        }
        printf("%d\n",(sum-mi-ma)/(n-2));
    }
    return(0);
}

