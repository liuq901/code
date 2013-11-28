#include <cstdio>
#include <cstring>
char s[100];
bool check()
{
    int n=strlen(s),a,b;
    a=b=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]!='4' && s[i]!='7')
            return(false);
        if (i<n/2)
            a+=s[i]-'0';
        else
            b+=s[i]-'0';
    }
    return(a==b);
}
int main()
{
    scanf("%*d%s",s);
    printf("%s\n",check()?"YES":"NO");
    return(0);
}

