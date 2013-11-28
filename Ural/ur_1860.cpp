#include <cstdio>
typedef long long ll;
const int mod=1000000007,maxn=1000010;
int fib[maxn],p[maxn],ans[maxn];
bool f[maxn];
void init(int n)
{
    for (int i=2;i*i<=n;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=n;j++)
        {
            f[i*j]=true;
            p[i*j]=i;
        }
    }
    fib[0]=fib[1]=1;
    for (int i=2;i<=n;i++)
    {
        fib[i]=(fib[i-2]+fib[i-1])%mod;
        if (!f[i])
            p[i]=i;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    init(n);
    for (int i=2;i<=n;i++)
    {
        int value=fib[n-i];
        for (int j=i;j!=1;j/=p[j])
            ans[p[j]]=(ans[p[j]]+value)%mod;
    }
    int sum=1;
    for (int i=2;i<=n;i++)
        sum=ll(sum)*(ans[i]+1)%mod;
    printf("%d\n",sum);
    return(0);
}

