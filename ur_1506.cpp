#include <cstdio>
int a[110];
int main()
{
    int n,K;
    scanf("%d%d",&n,&K);
    int p=(n+K-1)/K;
    for (int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int tot=0;
    for (int i=0;i<p;i++)
    {
        for (int j=0;j<K;j++)
        {
            if (i+j*p>=n)
                break;
            printf("%4d",a[i+j*p]);
        }
        printf("\n");
    }
    return(0);
}

