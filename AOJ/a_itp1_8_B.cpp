#include <cstdio>
#include <cstring>
char s[1000000];
int main()
{
    while (1)
    {
        scanf("%s",s);
        int len=strlen(s);
        if (s[0]=='0' && len==1)
            break;
        int ans=0;
        for (int i=0;i<len;i++)
            ans+=s[i]-'0';
        printf("%d\n",ans);
    }
    return(0);
}

