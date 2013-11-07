#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n,low=2,high=10;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        char buf[100];
        scanf("%d%s",&x,buf);
        if (buf[0]=='h')
            low=max(low,x);
        else
            high=min(high,x);
    }
    if (low>=high)
        printf("Inconsistent\n");
    else
        printf("%d\n",high);
    return(0);
}

