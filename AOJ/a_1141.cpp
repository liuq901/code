#include <cstdio>
const int N=1000010;
bool f[N];
void init()
{
    int n=1000000;
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
            f[i*j]=true;
    }
    f[0]=f[1]=true;
}
int main()
{
    init();
    while (1)
    {
        int a,d,n;
        scanf("%d%d%d",&a,&d,&n);
        if (a==0 && d==0 && n==0)
            break;
        while (1)
        {
            if (!f[a])
                n--;
            if (n==0)
                break;
            a+=d;
        }
        printf("%d\n",a);
    }
    return(0);
}

