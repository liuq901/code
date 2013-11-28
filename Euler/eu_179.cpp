#include <cstdio>
const int n=10000000;
int to[n+10],ans[n+10];
bool f[n+10];
void init()
{
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
        {
            f[i*j]=true;
            to[i*j]=i;
        }
    }
    for (int i=2;i<=n;i++)
    {
        if (f[i])
           continue;
        to[i]=i;
    }
}
int calc(int n)
{
    int ret=1;
    while (n>1)
    {
        int x=to[n],cnt=1;
        while (n%x==0)
        {
            cnt++;
            n/=x;
        }
        ret*=cnt;
    }
    return(ret);
}
int main()
{
    init();
    for (int i=2;i<n;i++)
        ans[i]=calc(i);
    int sum=0;
    for (int i=2;i<n;i++)
        sum+=ans[i]==ans[i+1];
    printf("%d\n",sum);
    return(0);
}

