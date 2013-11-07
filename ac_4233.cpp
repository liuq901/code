#include <cstdio>
#include <cstring>
#include <cctype>
char a[26],s[100000],t[100000];
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        gets(t);
        for (int i=0;i<26;i++)
            a[i]=t[i];
        int len=strlen(s);
        static int id=0;
        printf("%d ",++id);
        for (int i=0;i<len;i++)
            if (isalpha(s[i]))
                printf("%c",a[s[i]-'A']);
            else
                printf("%c",s[i]);
        printf("\n");
    }
    return(0);
}

