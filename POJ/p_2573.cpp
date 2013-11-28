#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    if (n==1)
        printf("%d\n%d\n",a[1],a[1]);
    else if (n==2)
        printf("%d\n%d %d\n",a[2],a[1],a[2]);
    else if (n==3)
    {
        printf("%d\n",a[1]+a[2]+a[3]);
        printf("%d %d\n",a[1],a[2]);
        printf("%d\n",a[1]);
        printf("%d %d\n",a[1],a[3]);
    }
    else
    {
        int ans=0;
        for (int i=n;i>3;i-=2)
        {
            int A=a[1],B=a[2],C=a[i-1],D=a[i];
            ans+=min((A<<1)+C+D,A+B*2+D);
        }
        if (n&1)
            ans+=a[1]+a[2]+a[3];
        else
            ans+=a[2];
        printf("%d\n",ans);
        for (int i=n;i>3;i-=2)
        {
            int A=a[1],B=a[2],C=a[i-1],D=a[i];
            if ((A<<1)+B+C+D<A+B*3+D)
            {
                printf("%d %d\n",A,D);
                printf("%d\n",A);
                printf("%d %d\n",A,C);
                printf("%d\n",A);
            }
            else
            {
                printf("%d %d\n",A,B);
                printf("%d\n",A);
                printf("%d %d\n",C,D);
                printf("%d\n",B);
            }
        }
        if (n&1)
            printf("%d %d\n%d\n%d %d\n",a[1],a[1],a[1],a[1],a[3]);
        else
            printf("%d %d\n",a[1],a[2]);
    }
    return(0);
}

