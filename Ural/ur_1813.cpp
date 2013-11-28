#include <cstdio>
bool f[100010];
int a[100010];
void init()
{
    for (int i=2;i*i<=100000;i++)
    {
        if (f[i])
            continue;
        for (int j=i;i*j<=100000;j++)
            f[i*j]=true;
    }
    for (int i=2;i<=100000;i++)
        if (!f[i])
            a[++a[0]]=i;
}
int get(int n)
{
    int ans=1;
    if (n%2==0)
        n/=2,ans=2;
    for (int i=1;i<=a[0];i++)
    {
        if (n==1)
            break;
        if (n%a[i]!=0)
            continue;
        ans*=a[i];
        while (n%a[i]==0)
            n/=a[i];
    }
    if (n!=1)
        ans*=n;
    return(ans);
}
int main()
{
    init();
    int n;
    while (scanf("%d",&n)==1)
    {
        int p=get(n),num=n/p;
        int l=1,r=1+(num-1)*p;
        printf("%.0f\n",(l+r)/2.0);
    }
    return(0);
}

