#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int ans=0;
    for (int i=1;i<=12000;i++)
    {
        int l=(i+2)/3,r=i/2;
        for (int j=l;j<=r;j++)
            ans+=__gcd(i,j)==1;
    }
    printf("%d\n",ans-2);
    return(0);
}

