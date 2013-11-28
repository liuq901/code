#include <cstdio>
typedef long long ll;
ll f(int x)
{
    return(x==0?1:f(x-1)*x);
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",f(n));
    return(0);
}

