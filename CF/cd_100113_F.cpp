#include <cstdio>
#include <algorithm>
using namespace std;
int a[310],c[310];
inline bool cmp(int x,int y)
{
    return(a[x]>a[y]);
}
int main()
{
    freopen("lan.in","r",stdin);
    freopen("lan.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
        c[i]=i;
    }
    sort(c+1,c+m+1,cmp);
    int k=-1,sum=0;
    for (int i=1;i<=m;i++)
    {
        sum+=a[c[i]];
        if (sum-2*i+2>=n)
        {
            k=i;
            break;
        }
    }
    if (k==-1)
        printf("Epic fail\n");
    else
    {
        printf("%d\n",k);
        for (int i=1;i<=k;i++)
            printf("%d%c",c[i],i==k?'\n':' ');
    }
    return(0);
}

