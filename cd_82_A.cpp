#include <cstdio>
typedef long long ll;
const char name[][10]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
int main()
{
    ll n,now=5;
    scanf("%I64d",&n);
    while (n>0)
    {
        n-=now;
        now<<=1;
    }
    now>>=1;
    n+=now;
    now/=5;
    printf("%s\n",name[(n-1)/now]);
    return(0);
}

