#include <cstdio>
#include <cstring>
char s[110];
int main()
{
    while (scanf("%s",s)==1)
    {
        int len=strlen(s);
        for (int i=0;i<len;i++)
        {
            if (s[i]=='@')
            {
                int t=s[i+1]-'0';
                for (int j=1;j<=t;j++)
                    printf("%c",s[i+2]);
                i+=2;
                continue;
            }
            printf("%c",s[i]);
        }
        printf("\n");
    }
    return(0);
}

