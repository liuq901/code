#include <cstdio>
#include <cstring>
#include <cctype>
char s[110],ans[210];
bool check(char ch)
{
    return(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='y');
}
int main()
{
    scanf("%s",s);
    int n=strlen(s),m=0;
    for (int i=0;i<n;i++)
    {
        s[i]=tolower(s[i]);
        if (check(s[i]))
            continue;
        ans[m++]='.';
        ans[m++]=s[i];
    }
    ans[m]='\0';
    printf("%s\n",ans);
    return(0);
}

