#include <cstdio>
int a[30],c[30];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int p=0;
    while (n!=0 || m!=0)
    {
        p++;
        a[p]=n%3;
        c[p]=m%3;
        n/=3,m/=3;
    }
    int ans=0;
    for (int i=p;i;i--)
        for (int j=0;j<3;j++)
            if ((a[i]+j)%3==c[i])
            {
                ans=ans*3+j;
                break;
            }
    printf("%d\n",ans);
    return(0);
}

