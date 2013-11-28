#include <cstdio>
int a[3010];
void work(int l,int r)
{
    if (l>r)
        return;
    if (l!=r)
        for (int i=l;i<=r;i++)
            if (a[i]>=a[r])
            {
                work(i,r-1);
                work(l,i-1);
                break;
            }
    static bool first=true;
    if (!first)
        printf(" ");
    first=false;
    printf("%d",a[r]);
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    work(1,n);
    printf("\n");
    return(0);
}

