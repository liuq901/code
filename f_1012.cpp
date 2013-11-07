#include <cstdio>
const int maxn=32000;
int a[33000];
bool f[33000];
void init()
{
    for (int i=2;i*i<=maxn;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=maxn;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=maxn;i++)
        if (!f[i])
            a[++a[0]]=i;
}
int power(int x,int k)
{
    int ret=1;
    for (int i=1;i<=k;i++)
        ret*=x;
    return(ret);
}
int main()
{
    init();
    while (1)
    {
        int n,ans=1;
        scanf("%d",&n);
        if (n==0)
            break;
        for (int i=1;i<=a[0];i++)
        {
            int x=0;
            while (n%a[i]==0)
            {
                x++;
                n/=a[i];
            }
            if (x!=0)
                ans*=(a[i]-1)*power(a[i],x-1);
        }
        if (n!=1)
            ans*=n-1;
        printf("%d\n",ans);
    }
    return(0);
}

