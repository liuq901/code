#include <cstdio>
typedef long long ll;
bool ans[50];
ll m,a[30],f[30];
void init()
{
    f[0]=1,a[0]=1;
    for (int i=1;i<=26;i++)
    {
        f[i]=a[i]=f[i-1];
        for (int j=1;j<i;j++)
            f[i]+=a[j]*f[i-j];
    }
}
void work(int n,int p,ll x)
{
    if (n==0)
        return;
    if (n==1)
    {
        ans[p]=true;
        ans[p+1]=false;
        return;
    }
    ll now=a[n]*x;
    if (now<=m)
        m-=now;
    else
    {
        ans[p]=true;
        ans[p+2*n-1]=false;
        work(n-1,p+1,x);
        return;
    }
    for (int i=n-1;i;i--)
    {
        now=a[i]*f[n-i]*x;
        if (now<=m)
            m-=now;
        else
        {
            work(i,p,x*f[n-i]);
            work(n-i,p+2*i,x);
            return;
        }
    }
}
int main()
{
    init();
    while (1)
    {
        int n;
        scanf("%d%I64d",&n,&m);
        if (n==0 && m==0)
            break;
        n--;
        if (m<=0 || m>f[n])
            printf("ERROR\n");
        else
        {
            m--;
            work(n,1,1);
            for (int i=1;i<=2*n;i++)
                printf("%s",ans[i]?"E":"S");
            printf("\n");
        }
    }
    return(0);
}

