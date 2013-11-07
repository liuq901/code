#include <cstdio>
typedef long long ll;
ll gcd(int a,int b)
{
    if (b==0)
        return(0);
    ll ret=a/b*b;
    return(ret+gcd(b,a%b));
}
int main()
{
    for (int i=1;i<=10;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%I64d\n",gcd(a,b));
    }
    return(0);
}

