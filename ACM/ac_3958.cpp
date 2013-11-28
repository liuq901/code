#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[1000];
int from(int base,char *s)
{
    int n=strlen(s),now=1,ret=0;
    for (int i=n-1;i>=0;i--)
    {
        ret+=(s[i]-'0')*now;
        now*=base;
    }
    return(ret);
}
void to(int base,int n,char *s)
{
    if (n==0)
    {
        s[0]='0';
        s[1]='\0';
        return;
    }
    int t=0;
    while (n)
    {
        int x;
        if (n>=n/base*base)
        {
            x=n-n/base*base;
            n/=base;
        }
        else
        {
            x=n-(n/base+1)*base;
            n=n/base+1;
        }
        s[t++]=x+'0';
    }
    s[t]='\0';
    reverse(s,s+t);
}
int main()
{
    while (1)
    {
        scanf("%s",s);
        if (s[0]=='e')
            break;
        else if (s[0]=='f')
        {
            int base;
            sscanf(s+5,"%d",&base);
            scanf("%s",s);
            printf("%d\n",from(-base,s));
        }
        else
        {
            int base,n;
            sscanf(s+3,"%d",&base);
            scanf("%d",&n);
            to(-base,n,s);
            printf("%s\n",s);
        }
    }
    return(0);
}

