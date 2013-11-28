#include <cstdio>
#include <cstring>
#include <cctype>
char s[1100];
int main()
{
    int T;
    scanf("%d",&T);
    gets(s);
    while (T--)
    {
        gets(s);
        int n=strlen(s),ans=0;
        for (int i=0;i<n;i++)
        {
            if (s[i]=='1')
                ans++;
            if (i>=2 && tolower(s[i-2])=='o' && tolower(s[i-1])=='n' && tolower(s[i])=='e')
                ans++;
        }
        printf("%d\n",ans);
    }
    return(0);
}

