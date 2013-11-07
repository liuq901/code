#include <cstdio>
#include <cstring>
#include <cctype>
char a[100];
int main()
{
    int n;
    scanf("%s%d",a,&n);
    int len=strlen(a);
    for (int i=0;i<len;i++)
    {
        a[i]=tolower(a[i]);
        char ch=a[i];
        if (ch<n+97)
            a[i]=toupper(a[i]);
        else
            a[i]=tolower(a[i]);
    }
    printf("%s\n",a);
    return(0);
}

