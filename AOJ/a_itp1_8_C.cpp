#include <cstdio>
#include <cstring>
#include <cctype>
int a[260];
char s[1000000];
int main()
{
    while (gets(s))
    {
        int len=strlen(s);
        for (int i=0;i<len;i++)
            a[tolower(s[i])]++;
    }
    for (char ch='a';ch<='z';ch++)
        printf("%c : %d\n",ch,a[ch]);
    return(0);
}

