#include <cstdio>
#include <cstring>
char s[1010];
int main()
{
    scanf("%s",s);
    int n=strlen(s),ans=1,sum=1;
    for (int i=1;i<n;i++)
    {
        if (sum==5 || s[i]!=s[i-1])
        {
            ans++;
            sum=1;
            continue;
        }
        sum++;
    }
    printf("%d\n",ans);
    return(0);
}

