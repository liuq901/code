#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct bignum
{
    int a[2010];
    bignum(int x=0)
    {
        memset(a,0,sizeof(a));
        while (x)
        {
            a[++a[0]]=x%10;
            x/=10;
        }
        a[0]=max(a[0],1);
    }
    void print(int len)
    {
        while (a[0]<len)
            a[++a[0]]=0;
        int p=1;
        while (a[p]==0)
            p++;
        for (int i=a[0];i>=p;i--)
        {
            if (i==len)
                printf(".");
            printf("%d",a[i]);
        }
        printf("\n");
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
bignum operator *(const bignum &a,int b)
{
    bignum c;
    c[0]=a[0];
    int x=0;
    for (int i=1;i<=c[0];i++)
    {
        c[i]=a[i]*b+x;
        x=c[i]/10;
        c[i]%=10;
    }
    while (x)
    {
        c[++c[0]]=x%10;
        x/=10;
    }
    return(c);
}
char s[10];
int main()
{
    int n;
    while (scanf("%s%d",s,&n)==2)
    {
        int x=0,pos;
        for (int i=0;i<6;i++)
            if (s[i]=='.')
                pos=i;
            else
                x=x*10+s[i]-'0';
        bignum ans(1);
        for (int i=1;i<=n;i++)
            ans=ans*x;
        int length=n*(5-pos);
        ans.print(length);
    }
    return(0);
}

