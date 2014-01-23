#include <cstdio>
#include <algorithm>
using namespace std;
int a[30];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        scanf("%d",&a[x]);
    }
    printf("%d %d\n",max_element(a+1,a+n+1)-a,*max_element(a+1,a+n+1));
    return(0);
}

