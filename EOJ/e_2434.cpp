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
        int a,b,p;
        scanf("%d%d",&a,&b);
        p=__gcd(a,b);
        for (int i=3;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            p=__gcd(p,x);
        }
        printf("%d\n",p);
    }
    return(0);
}

