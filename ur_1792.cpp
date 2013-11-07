#include <cstdio>
int a[10];
bool check()
{
    int x=a[2]+a[3]+a[4]&1,y=a[1]+a[3]+a[4]&1,z=a[1]+a[2]+a[4]&1;
    return(x==a[5] && y==a[6] && z==a[7]);
}
int main()
{
    for (int i=1;i<=7;i++)
        scanf("%d",&a[i]);
    for (int i=0;i<=7;i++)
    {
        a[i]^=1;
        if (check())
            break;
        a[i]^=1;
    }
    for (int i=1;i<=7;i++)
        printf("%d%c",a[i],i==7?'\n':' ');
    return(0);
}

