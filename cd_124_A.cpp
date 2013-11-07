#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    a++;
    b=n-b;
    printf("%d\n",n-max(a,b)+1);
    return(0);
}

