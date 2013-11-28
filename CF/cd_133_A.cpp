#include <cstdio>
#include <cstring>
char s[110];
int main()
{
    gets(s);
    int n=strlen(s);
    bool flag=false;
    for (int i=0;i<n;i++)
        if (s[i]=='H' || s[i]=='Q' || s[i]=='9')
        {
            flag=true;
            break;

        }
    printf("%s\n",flag?"YES":"NO");
    return(0);
}

