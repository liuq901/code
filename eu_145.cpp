#include <cstdio>
int reverse(int x)
{
    int ret=0;
    while (x)
    {
        ret=ret*10+x%10;
        x/=10;
    }
    return(ret);
}
bool check(int x)
{
    while (x)
    {
        if (x%2==0)
            return(false);
        x/=10;
    }
    return(true);
}
int main()
{
    int ans=0;
    for (int i=1;i<=1000000000;i++)
    {
        if (i%10==0)
            continue;
        ans+=check(i+reverse(i));
    }
    printf("%d\n",ans);
    return(0);
}

