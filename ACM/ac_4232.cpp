#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        static int id=0;
        int p=__gcd(x,y);
        printf("%d %d %d\n",++id,x/p*y,p);
    }
    return(0);
}

