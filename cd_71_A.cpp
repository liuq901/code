#include <cstdio>
#include <cstring>
char s[110];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int n=strlen(s);
        if (n>10)
            printf("%c%d%c\n",s[0],n-2,s[n-1]);
        else
            printf("%s\n",s);
    }
    return(0);
}

