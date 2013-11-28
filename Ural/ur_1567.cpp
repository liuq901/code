#include <cstdio>
#include <cstring>
int a[260];
char s[100000];
int main()
{
    for (int i='a';i<='z';i++)
        a[i]=(i-'a')%3+1;
    a[' ']=1;
    a['.']=1;
    a[',']=2;
    a['!']=3;
    gets(s);
    int n=strlen(s),ans=0;
    for (int i=0;i<n;i++)
        ans+=a[s[i]];
    printf("%d\n",ans);
    return(0);
}

