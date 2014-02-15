#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    while (1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (a==0 && b==0 && c==0)
            break;
        if (a>b)
            swap(a,b);
        if (a>c)
            swap(a,c);
        if (b>c)
            swap(b,c);
        int T;
        scanf("%d",&T);
        while (T--)
        {
            int x;
            scanf("%d",&x);
            x<<=1;
            printf("%s\n",a*a+b*b<x*x?"OK":"NA");
        }
    }
    return(0);
}

