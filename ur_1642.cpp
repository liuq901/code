#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main()
{
    int n,x,l,r;
    l=r=1<<30;
    scanf("%d%d",&n,&x);
    if (x<0)
        l=-x;
    else
        r=x;
    for (int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        if (t*x>0 && abs(t)<abs(x))
        {
            l=r=0;
            break;
        }
        if (x<0 && t>0)
            r=min(r,2*t-x);
        if (x>0 && t<0)
            l=min(l,x-2*t);
    }
    if (l==0 && r==0)
        printf("Impossible\n");
    else
        printf("%d %d\n",r,l);
    return(0);
}

