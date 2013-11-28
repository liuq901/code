#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    unsigned long long a,b,c;
    while (scanf("%llu%llu%llu",&a,&b,&c)==3)
        printf("%llu\n",a+b+c-2*min(min(a,b),c));
    return(0);
}

