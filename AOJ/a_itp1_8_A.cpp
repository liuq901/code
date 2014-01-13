#include <cstdio>
#include <cstring>
#include <cctype>
char s[1000000];
int main()
{
    gets(s);
    int len=strlen(s);
    for (int i=0;i<len;i++)
        s[i]=islower(s[i])?toupper(s[i]):tolower(s[i]);
    printf("%s\n",s);
    return(0);
}

