#include <cstdio>
int main()
{
    int n,a[10];
    scanf("%d",&n);
    a[0]=0;
    for (int i=1;i<=7;i++)
    {
        scanf("%d",&a[i]);
        a[0]+=a[i];
    }
    n%=a[0];
    if (n==0)
        n=a[0];
    for (int i=1;i<=7;i++)
    {
        n-=a[i];
        if (n<=0)
        {
            printf("%d\n",i);
            break;
        }
    }
    return(0);
}

