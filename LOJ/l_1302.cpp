#include <cstdio>
#include <cstring>
typedef long long ll;
char a[80];
ll f[80][80];
bool check(char c1,char c2,char c3)
{
    return((c1=='R')+(c2=='R')+(c3=='R')<=1);
}
ll dp(int l,int r)
{
    if (l>r)
        return(1);
    if (f[l][r]!=-1)
        return(f[l][r]);
    ll &ret=f[l][r];
    ret=0;
    for (int i=l+1;i<=r;i++)
        for (int j=i+1;j<=r;j++)
            if (check(a[l],a[i],a[j]))
                ret+=dp(l+1,i-1)*dp(i+1,j-1)*dp(j+1,r);
    return(ret);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",a+1);
        memset(f,-1,sizeof(f));
        static int id=0;
        printf("Case %d: %lld\n",++id,dp(1,strlen(a+1)));
    }
    return(0);
}

