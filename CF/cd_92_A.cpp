#include <cstdio>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int sum=n*(n+1)/2;
    m%=sum;
    for (int i=1;i<=n;i++)
    {
        if (m<i)
            break;
        m-=i;
    }
    printf("%d\n",m);
    return(0);
}

