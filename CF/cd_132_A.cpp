#include <cstdio>
#include <cstring>
char s[100010];
int calc(int x)
{
    int a[10];
    for (int i=0;i<8;i++)
    {
        a[i]=x&1;
        x>>=1;
    }
    int ret=0;
    for (int i=0;i<8;i++)
        ret=ret<<1|a[i];
    return(ret);
}
int getmod(int x)
{
    x%=256;
    if (x<0)
        x+=256;
    return(x);
}
int main()
{
    gets(s);
    int n=strlen(s),now=0;
    for (int i=0;i<n;i++)
    {
        int p=calc(int(s[i])),x=getmod(now-p);
        printf("%d\n",x);
        now=p;
    }
    return(0);
}

