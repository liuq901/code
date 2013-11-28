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
        for (int i=b+1;;i++)
            if (__gcd(a,i)==b)
            {
                printf("%d\n",i);
                break;
            }
    }
    return(0);
}

