#include <cstdio>
#include <cstring>
#include <cctype>
char s[10000];
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        int len=strlen(s),ans=0;
        for (int i=1;i<=len;i++)
            ans+=isalpha(s[i-1]) && !isalpha(s[i]);
        printf("%d\n",ans);
    }
    return(0);
}

