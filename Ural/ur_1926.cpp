#include <cstdio>
#include <cstring>
typedef long long ll;
char s[100010];
int n,len,a[100],p[100],b[100][100010];
bool prime(int n)
{
    for (int i=2;i*i<=n;i++)
        if (n%i==0)
            return(false);
    return(true);
}
void init()
{
    for (int i=2;i<=47;i++)
        if (prime(i))
            p[++n]=i;
}
ll power(ll x,int y,int mod)
{
    ll ret=1;
    for (int i=1;i<=y;i++)
        ret=ret*x%mod;
    return(ret);
}
ll query(ll M)
{
    if (M==1)
        return(0);
    ll ans=0;
    for (int i=1;i<=n;i++)
        if (M%p[i]==0)
        {
            ll e=M/p[i],d=a[i]*power(e,p[i]-2,p[i])%p[i];
            ans=(ans+e*d)%M;
        }
    return(ans);
}
void modify(int pos,int value)
{
    pos=len-pos;
    int old=s[pos]-'0';
    for (int i=1;i<=n;i++)
    {
        a[i]=(a[i]+(value-old)*b[i][pos])%p[i];
        if (a[i]<0)
            a[i]+=p[i];
    }
    s[pos]=value+'0';
}
int main()
{
    init();
    scanf("%s",s);
    len=strlen(s);
    for (int i=1;i<=n;i++)
        for (int j=0;j<len;j++)
            a[i]=(a[i]*10+s[j]-'0')%p[i];
    for (int i=1;i<=n;i++)
    {
        b[i][len-1]=1;
        for (int j=len-2;j>=0;j--)
            b[i][j]=b[i][j+1]*10%p[i];
    }
    int K;
    scanf("%d",&K);
    for (int i=1;i<=K;i++)
    {
        int op;
        scanf("%d",&op);
        if (op==0)
        {
            ll x;
            scanf("%lld",&x);
            printf("%lld\n",query(x));
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            modify(x,y);
        }
    }
    return(0);
}

