#include <cstdio>
#include <algorithm>
using namespace std;
int a[10];
int main()
{
    for (int i=1;i<=5;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+6);
    for (int i=5;i;i--)
        printf("%d%c",a[i],i==1?'\n':' ');
    return(0);
}

