#include <cstdio>
int main()
{
    int a,b,n;
    while (scanf("%d%d%d",&a,&b,&n)==3)
    {
        a%=b;
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            a*=10;
            ans+=a/b;
            a%=b;
        }
        printf("%d\n",ans);
    }
    return(0);
}

