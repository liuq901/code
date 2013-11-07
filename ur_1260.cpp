#include <cstdio>
#include <algorithm>
using namespace std;
int a[60];
int main()
{
    int n;
    scanf("%d",&n);
    a[1]=1;
    a[2]=1;
    a[3]=2;
    for (int i=4;i<=n;i++)
        a[i]=a[i-1]+a[i-3]+1;
    printf("%d\n",a[n]);
    return(0);
}

