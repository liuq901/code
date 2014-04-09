#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int a[31];
        for (int i=0;i<=30;i++)
            a[i]=n>>i&1;
        reverse(a,a+31);
        next_permutation(a,a+31);
        reverse(a,a+31);
        int ans=0;
        for (int i=0;i<=30;i++)
            ans|=a[i]<<i;
        static int id=0;
        printf("Case %d: %d\n",++id,ans);
    }
    return(0);
}

