#include <cstdio>
int a[1010];
int main()
{
    int n;
    scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if (sum%n!=0)
        printf("Unrecoverable configuration.\n");
    else
    {
        int k=sum/n,p,q,x,y;
        p=q=0;
        for (int i=1;i<=n;i++)
            if (a[i]<k)
            {
                p++;
                x=i;
            }
            else if (a[i]>k)
            {
                q++;
                y=i;
            }
        if (p==0 && q==0)
            printf("Exemplary pages.\n");
        else if (p==1 && q==1)
            printf("%d ml. from cup #%d to cup #%d.\n",k-a[x],x,y);
        else
            printf("Unrecoverable configuration.\n");
    }
    return(0);
}

