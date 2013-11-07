#include <cstdio>
#include <cstring>
const char hello[]="hello";
char s[110];
int main()
{
    scanf("%s",s);
    int now=0,n=strlen(s);
    for (int i=0;i<n;i++)
    {
        if (s[i]==hello[now])
            now++;
        if (now==5)
            break;
    }
    printf("%s\n",now==5?"YES":"NO");
    return(0);
}

