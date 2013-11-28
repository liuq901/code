#include <cstdio>
#include <algorithm>
using namespace std;
int a[110],b[110];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if (m<=0 || m>sum)
        printf("No\n");
    else if (n==1)
        if (a[1]==m)
        {
            printf("Yes\n");
            for (int i=1;i<=a[1];i++)
                printf("1 1%c",i==a[1]?'\n':' ');
        }
        else
            printf("No\n");
    else if (m==1)
    {
        int k=-1;
        for (int i=1;i<=n;i++)
            if (a[i]==1)
            {
                k=i;
                break;
            }
        if (k==-1)
            printf("No\n");
        else
        {
            printf("Yes\n");
            printf("%d",k);
            for (int i=1;i<=n;i++)
                if (i!=k)
                    for (int j=1;j<=a[i];j++)
                        printf(" %d %d",i,i);
            printf(" %d\n",k);
        }
    }
    else
    {
        printf("Yes\n");
        int p=m-2;
        a[1]--,a[2]--;
        for (int i=1;i<=n;i++)
        {
            b[i]=min(p,a[i]);
            p-=b[i];
        }
        printf("1");
        for (int i=2;i<=n;i++)
            for (int j=1;j<=a[i]-b[i];j++)
                printf(" %d %d",i,i);
        printf(" 1 2");
        for (int i=1;i<=a[1]-b[1];i++)
            printf(" 1 1");
        printf(" 2");
        for (int i=1;i<=n;i++)
            for (int j=1;j<=b[i];j++)
                printf(" %d %d",i,i);
        printf("\n");
    }
    return(0);
}

