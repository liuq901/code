#include <cstdio>
int main()
{
    int n,t,s;
    scanf("%d%d%d",&n,&t,&s);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        printf("%f\n",x+(t-(x-s))/2.0);
    }
    return(0);
}

