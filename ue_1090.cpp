#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010],c[1010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]==a[i-1])
                c[i]=c[i-1]+1;
            else
                c[i]=1;
        }
        int ans=*max_element(c+1,c+n+1);
        printf("%d %d\n",count(c+1,c+n+1,ans),ans);
        for (int i=1;i<=n;i++)
        {
            if (i!=1)
                printf(",");
            if (a[i]!=a[i-1])
                printf("{");
            printf("%d",a[i]);
            if (i==n || a[i]!=a[i+1])
                printf("}");
        }
        printf("\n");
    }
    return(0);
}

