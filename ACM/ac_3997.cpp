#include <cstdio>
#include <cstring>
class bignum
{
    int a[2010];
public:
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%10;
            x/=10;
        }
        if (!a[0])
            a[0]=1;
    }
    bignum(char *s)
    {
        memset(a,0,sizeof(a));
        a[0]=strlen(s);
        for (int i=1;i<=a[0];i++)
            a[i]=s[a[0]-i]-'0';
    }
    int &operator [](int x)
    {
        return(a[x]);
    }
    int operator [](int x) const
    {
        return(a[x]);
    }
};
int operator %(const bignum a,int b)
{
    int x=0;
    for (int i=a[0];i;i--)
        x=(x*10+a[i])%b;
    return(x);
}
char s[2010];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int x;
        scanf("%d%s",&x,s);
        bignum a(s);
        printf("%d\n",a%x);
    }
    return(0);
}

