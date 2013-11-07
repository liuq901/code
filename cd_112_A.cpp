#include <cstdio>
#include <cstring>
#include <cctype>
char a[110],b[110];
int main()
{
    scanf("%s%s",a,b);
    int n=strlen(a);
    for (int i=0;i<n;i++)
    {
        a[i]=tolower(a[i]);
        b[i]=tolower(b[i]);
    }
    printf("%d\n",strcmp(a,b));
    return(0);
}

