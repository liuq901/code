#include <cstdio>
#include <algorithm>
using namespace std;
int a[20010];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        sum+=a[i];
        if (sum>=m)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

