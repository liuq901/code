#include <cstdio>
#include <cstring>
#include <cctype>
char s[10000];
int main()
{
    scanf("%s",s);
    int n=strlen(s),a=0,b=0;
    for (int i=0;i<n;i++)
        if (islower(s[i]))
            a++;
        else
            b++;
    for (int i=0;i<n;i++)
        s[i]=a>=b?tolower(s[i]):toupper(s[i]);
    printf("%s\n",s);
    return(0);
}

