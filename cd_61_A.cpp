#include <cstdio>
#include <cstring>
char s[100000],t[100000];
int main()
{
    scanf("%s%s",s,t);
    int n=strlen(s);
    for (int i=0;i<n;i++)
        printf("%c",s[i]==t[i]?'0':'1');
    printf("\n");
    return(0);
}

