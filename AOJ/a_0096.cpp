#include <cstdio>
#include <algorithm>
using namespace std;
int p[2010];
int main()
{
    for (int i=0;i<=1000;i++)
        for (int j=0;j<=1000;j++)
            p[i+j]++;
    int n;
    while (scanf("%d",&n)==1)
    {
        int ans=0;
        for (int i=0;i<=min(n,1000);i++)
            for (int j=0;j<=min(n-i,1000);j++)
                if (n-i-j<=2000)
                    ans+=p[n-i-j];
        printf("%d\n",ans);
    }
    return(0);
}

