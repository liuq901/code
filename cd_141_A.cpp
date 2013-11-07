#include <cstdio>
#include <cstring>
int a[210];
char s[110];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    for (int i=0;i<n;i++)
        a[s[i]]++;
    scanf("%s",s);
    n=strlen(s);
    for (int i=0;i<n;i++)
        a[s[i]]++;
    scanf("%s",s);
    n=strlen(s);
    for (int i=0;i<n;i++)
        a[s[i]]--;
    bool flag=true;
    for (int i='A';i<='Z';i++)
        if (a[i]!=0)
        {
            flag=false;
            break;
        }
    printf("%s\n",flag?"YES":"NO");
    return(0);
}

