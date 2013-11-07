#include <cstdio>
#include <cstring>
char s[100000];
int main()
{
    scanf("%s",s);
    int n=strlen(s),ans=1,now=1;
    for (int i=1;i<n;i++)
    {
        if (s[i]==s[i-1])
            now++;
        else
            now=1;
        if (now>ans)
            ans=now;
    }
    printf("%s\n",ans>=7?"YES":"NO");
    return(0);
}

