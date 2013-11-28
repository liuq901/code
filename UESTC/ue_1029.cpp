#include <cstdio>
#include <cstring>
#include <cctype>
char s[10000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int n=strlen(s),now=-1;
        for (int i=0;i<=n;i++)
            if (isdigit(s[i]))
            {
                if (now==-1)
                    now=0;
                now=now*10+s[i]-'0';
            }
            else
            {
                if (now!=-1)
                    printf("%d ",now);
                now=-1;
            }
        printf("\n");
    }
    return(0);
}

