#include <cstdio>
int main()
{
    int n,a,b,c;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    n<<=1;
    int ans=0;
    for (int i=0;i<=b;i++)
    {
        if (2*i>n)
            break;
        for (int j=0;j<=c;j++)
        {
            if (2*i+4*j>n)
                break;
            ans+=n-2*i-4*j<=a;
        }
    }
    printf("%d\n",ans);
    return(0);
}

