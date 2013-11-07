#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        int e=a*d+c*b,f=b*d,p=__gcd(e,f);
        printf("%d %d\n",e/p,f/p);
    }
    return(0);
}

