#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for (int i=0;i<n;i++)
            scanf("%d",&a[i]);
        printf("%d\n",*max_element(a,a+n)-*min_element(a,a+n)<<1);
    }
    return(0);
}

