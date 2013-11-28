#include <cstdio>
typedef long long ll;
ll check(ll n)
{
    for (int i=10;i;i--)
    {
        if (n%10!=i%10)
            return(false);
        n/=100;
    }
    return(true);
}
int main()
{
    for (int i=1000000000;;i+=10)
        if (check(ll(i)*i))
        {
            printf("%d\n",i);
            break;
        }
    return(0);
}

