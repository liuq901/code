#include <cstdio>
#include <cstring>
#include <cctype>
char s[100000];
int main()
{
    int ans=0;
    while (gets(s))
    {
        int len=strlen(s);
        for (int i=0;i<len;i++)
            if (isdigit(s[i]) && (i==0 || !isdigit(s[i-1])))
            {
                int x;
                sscanf(s+i,"%d",&x);
                ans+=x;
            }
    }
    printf("%d\n",ans);
    return(0);
}

