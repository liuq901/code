#include <cstdio>
#include <cstring>
char buf[1000000];
int main()
{
    while (1)
    {
        scanf("%s",buf);
        if (buf[0]=='0')
            break;
        int len=strlen(buf),x=0,y=0;
        for (int i=1;i<len;i++)
            buf[i]=='A'?x++:y++;
        x>y?x++:y++;
        printf("%d %d\n",x,y);
    }
    return(0);
}

