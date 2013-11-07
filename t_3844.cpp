#include <cstdio>
#include <cstring>
char buf[100];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",buf);
        int x=0,len=strlen(buf);
        for (int i=0;i<len;i++)
            x=x<<1|buf[i]-'0';
        printf("%o\n",x);
    }
    return(0);
}

