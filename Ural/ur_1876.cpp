#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int c,d;
    c=b*2+40,d=40+39*2+(a-40)*2+1;
    printf("%d\n",max(c,d));
    return(0);
}

