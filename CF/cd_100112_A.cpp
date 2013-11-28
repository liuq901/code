#include <cstdio>
#include <cstring>
char s[1010],t[1010];
int main()
{
    scanf("%s%s",s,t);
    int n=strlen(s),m=strlen(t);
    printf("%s\n",n<m?"no":"go");
    return(0);
}

