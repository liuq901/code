#include <cstdio>
#include <cstring>
const char op[]="><+-.,[]";
const int mod=1000003;
int a[260];
char s[110];
int main()
{
    for (int i=0;i<8;i++)
        a[op[i]]=i+8;
    scanf("%s",s);
    int ans=0,n=strlen(s);
    for (int i=0;i<n;i++)
        ans=(ans<<4|a[s[i]])%mod;
    printf("%d\n",ans);
    return(0);
}

