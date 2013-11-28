#include <cstdio>
#include <cstring>
#include <cctype>
char s[1000];
int a[1000];
int calc(char ch)
{
    ch=tolower(ch);
    if (ch<='c')
        return(2);
    else if (ch<='f')
        return(3);
    else if (ch<='i')
        return(4);
    else if (ch<='l')
        return(5);
    else if (ch<='o')
        return(6);
    else if (ch<='s')
        return(7);
    else if (ch<='v')
        return(8);
    else
        return(9);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int len=strlen(s);
        for (int i=0;i<len;i++)
            a[i]=calc(s[i]);
        bool flag=true;
        for (int i=0;i<len;i++)
            if (a[i]!=a[len-i-1])
            {
                flag=false;
                break;
            }
        printf("%s\n",flag?"YES":"NO");
    }
    return(0);
}

