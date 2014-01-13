#include <cstdio>
bool prime(int n)
{
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return(false);
    return(true);
}
int main()
{
    int n,ans=0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans+=prime(x);
    }
    printf("%d\n",ans);
    return(0);
}

