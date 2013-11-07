#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        int p=i-x+1;
        if (p<=0)
            p+=n;
        a[p]++;
    }
    printf("%d\n",max_element(a+1,a+n+1)-a);
    return(0);
}

