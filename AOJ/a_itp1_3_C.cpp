#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    while (1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if (a==0 && b==0)
            break;
        printf("%d %d\n",min(a,b),max(a,b));
    }
    return(0);
}

