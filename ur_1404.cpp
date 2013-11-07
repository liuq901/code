#include <cstdio>
#include <cstring>
char s[1010];
int main()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    s[0]='a'+5;
    for (int i=n;i;i--)
    {
        s[i]-=s[i-1]-'a';
        if (s[i]<'a')
            s[i]+=26;
    }
    printf("%s\n",s+1);
    return(0);
}

