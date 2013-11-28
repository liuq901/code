#include <cstdio>
int main()
{
    int n,min,max,a[110];
    scanf("%d",&n);
    min=1<<30,max=-min;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]>max)
            max=a[i];
        if (a[i]<min)
            min=a[i];
    }
    int ans,l,r;
    for (int i=1;i<=n;i++)
        if (a[i]==max)
        {
            ans=i-1;
            l=i;
            break;
        }
    for (int i=n;i;i--)
        if (a[i]==min)
        {
            ans+=n-i;
            r=i;
            break;
        }
    if (l>r)
        ans--;
    printf("%d\n",ans);
    return(0);
}

