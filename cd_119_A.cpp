#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,a[2];
    scanf("%d%d%d",&a[0],&a[1],&n);
    int now=0;
    while (1)
    {
        int p=__gcd(n,a[now]);
        if (n<p)
        {
            printf("%d\n",now^1);
            break;
        }
        n-=p;
        now^=1;
    }
    return(0);
}

