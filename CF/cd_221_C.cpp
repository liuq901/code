#include <cstdio>
#include <algorithm>
using namespace std;
int a[100010],b[100010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    int cnt=0;
    for (int i=1;i<=n;i++)
        cnt+=a[i]!=b[i];
    printf("%s\n",cnt<=2?"YES":"NO");
    return(0);
}

