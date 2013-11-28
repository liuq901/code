#include <cstdio>
#include <cstring>
#include <cctype>
char s[10010];
int main()
{
    bool first=true;
    while (gets(s))
    {
        int n=strlen(s);
        for (int i=0;i<n;i++)
        {
            if (isalpha(s[i]) && first)
            {
                first=false;
                s[i]=toupper(s[i]);
            }
            else
                s[i]=tolower(s[i]);
            if (s[i]=='.' || s[i]=='?' || s[i]=='!')
                first=true;
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return(0);
}

