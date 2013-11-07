#include <cstdio>
int calc(int x)
{
    if (x==0)
        return(0);
    return(calc(x/10)+(x%10==2));
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int ans=0;
    for (int i=a;i<=b;i++)
        ans+=calc(i);
    printf("%d\n",ans);
    return(0);
}

