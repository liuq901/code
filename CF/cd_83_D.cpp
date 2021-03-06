#include <cstdio>
bool prime(int x)
{
    for (int i=2;i*i<=x;i++)
        if (x%i==0)
            return(false);
    return(true);
}
int calc(int n,int K)
{
    if (!prime(K) || n<K)
        return(0);
    if (n/K<K)
        return(1);
    int ans=n/K;
    for (int i=2;i<K;i++)
        ans-=calc(n/K,i);
    return(ans);
}
int main()
{
    int a,b,k;
    scanf("%d%d%d",&a,&b,&k);
    printf("%d\n",calc(b,k)-calc(a-1,k));
    return(0);
}

