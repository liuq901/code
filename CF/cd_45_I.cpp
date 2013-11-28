#include <cstdio>
#include <algorithm>
using namespace std;
bool f[110];
int a[110];
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]==0)
            continue;
        f[i]=true;
        sum+=a[i]<0;
    }
    a[0]=-1<<30;
    if (sum&1)
    {
        int k=0;
        for (int i=1;i<=n;i++)
            if (a[i]<0 && a[i]>a[k])
                k=i;
        f[k]=false;
    }
    if (count(f+1,f+n+1,true)==0)
    {
        int k=0;
        for (int i=1;i<=n;i++)
            if (a[i]>a[k])
                k=i;
        f[k]=true;
    }
    bool first=true;
    for (int i=1;i<=n;i++)
    {
        if (!f[i])
            continue;
        if (!first)
            printf(" ");
        first=false;
        printf("%d",a[i]);
    }
    printf("\n");
    return(0);
}

