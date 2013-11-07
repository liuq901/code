#include <cstdio>
typedef long long ll;
ll a[50];
int main()
{
    int n;
    scanf("%d",&n);
    a[1]=1;
    for (int i=2;i<=n;i++)
        a[i]=(a[i-1]+1)*3;
    for (int i=n;i;i--)
        printf("%lld ",a[i]);
    printf("\n");
    return(0);
}

