#include <cstdio>
#include <algorithm>
using namespace std;
int a[100];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",*max_element(a+1,a+n+1));
    }
    return(0);
}

