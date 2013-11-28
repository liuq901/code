#include <cstdio>
#include <cstring>
#include <cctype>
int a[30];
char s[100000];
int main()
{
    gets(s);
    int n=strlen(s);
    int tot=0;
    for (int i=0;i<n;i++)
        if (isalpha(s[i]))
        {
            tot++;
            a[s[i]-'a']++;
        }
    int p=26;
    for (int i=0;i<26;i++)
        if (a[i]>a[p])
            p=i;
    printf("%c %.2f\n",p+'a',double(a[p])/tot);
    return(0);
}

