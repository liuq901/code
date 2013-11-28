#include <cstdio>
#include <cstring>
char s[100000];
int main()
{
    scanf("%s",s);
    int n=strlen(s),a=0,b=0;
    for (int i=0;i<n;i++)
        if (s[i]=='4')
            a++;
        else if (s[i]=='7')
            b++;
    if (a==0 && b==0)
        printf("-1\n");
    else if (a>=b)
        printf("4\n");
    else
        printf("7\n");
    return(0);
}

