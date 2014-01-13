#include <cstdio>
#include <cstring>
#include <cctype>
char s[10000],t[10000];
char *change(char *t)
{
    int len=strlen(t);
    for (int i=0;i<len;i++)
        t[i]=tolower(t[i]);
    return(t);
}
int main()
{
    scanf("%s",s);
    change(s);
    int ans=0;
    while (scanf("%s",t)==1)
        ans+=strcmp(s,change(t))==0;
    printf("%d\n",ans);
    return(0);
}

