#include <cstdio>
#include <algorithm>
using namespace std;
int a[50010];
int main()
{
    a[1]=1;
    for (int i=2;i<=50000;i++)
    {
        a[i]=a[i/2];
        if (i%2==1)
            a[i]+=a[i/2+1];
    }
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        int ans=*max_element(a+1,a+n+1);
        printf("%d %d %d ",a[n],ans,count(a+1,a+n+1,ans));
        for (int i=1;i<=n;i++)
            if (a[i]==ans)
                printf("%d ",i);
        printf("\n");
    }
    return(0);
}

