#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id,n,ans=0;
        scanf("%d%d",&id,&n);
        for (int i=1;i<=n/3;i++)
        {
            if (n-2*i<2*i)
                ans++;
            int x=max(i+1,(n-2*i)/2+1),y=n-i-x;
            if (y<x)
                continue;
            ans+=(y-x)&1?y-x+1:(y-x+1)/2*2+1;
        }
        printf("%d %d\n",id,ans);
    }
    return(0);
}

