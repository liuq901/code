#include <cstdio>
#include <cstring>
char s[1000000];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int id;
        scanf("%d",&id);
        gets(s);
        gets(s);
        int n,len=strlen(s);
        scanf("%d",&n);
        int now=0;
        printf("%d ",id);
        for (int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            now=(now+x+len)%len;
            printf("%c",s[now]);
        }
        printf("\n");
    }
    return(0);
}

