#include <cstdio>
#include <cstring>
#include <cctype>
char s[110];
int main()
{
    scanf("%s",s);
    int n=strlen(s),sum=0;
    for (int i=0;i<n;i++)
        if (isupper(s[i]))
            sum++;
    if (sum==n || sum==n-1 && islower(s[0]))
        for (int i=0;i<n;i++)
            if (isupper(s[i]))
                s[i]=tolower(s[i]);
            else
                s[i]=toupper(s[i]);
    printf("%s\n",s);
    return(0);
}

