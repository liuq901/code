#include <cstdio>
int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)==3)
    {
        int ans=0;
        a+=b;
        while (a>=c)
        {
            ans+=a/c;
            a=a/c+a%c;
        }
        printf("%d\n",ans);
    }
    return(0);
}

