#include <cstdio>
int a[200010],d[200010];
int main()
{
    int n,D;
    scanf("%d%d",&n,&D);
    for (int i=1;i<=n;i++)
        scanf("%d%d",&d[i],&a[i]);
    int k=1,ma=0,x=-1,y=-1,now=1;
    for (int i=1;i<=n;i++)
    {
        while (d[i]-d[now]>=D)
        {
            if (a[now]>a[k])
                k=now;
            now++;
        }
        if (now!=1 && a[i]+a[k]>ma)
        {
            ma=a[i]+a[k];
            x=k,y=i;
        }
    }
    printf("%d %d\n",x,y);
    return(0);
}

