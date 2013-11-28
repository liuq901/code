#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int t=__gcd(a,b);
        static int id=0;
        printf("%d %d %d\n",++id,a/t*b,t);
    }
    return(0);
}

