#include <cstdio>
int a[100000];
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (n==-1)
            break;
        int m=0;
        while (n)
        {
            a[++m]=n&3;
            n>>=2;
        }
        if (m==0)
            a[m=1]=0;
        for (int i=m;i;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return(0);
}

