#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if (n==21)
        printf("1\n");
    else
    {
        int ans=1<<30;
        for (int i=1;i<=6;i++)
            for (int j=1;j<=6;j++)
            {
                int p=n-i-j;
                if (p>0 && p%14==0 && p/14>1)
                    ans=min(ans,p/14);
            }
        if (ans==1<<30)
            ans=-1;
        printf("%d\n",ans);
    }
    return(0);
}

