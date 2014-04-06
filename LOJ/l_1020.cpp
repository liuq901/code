#include <cstdio>
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        char s[10];
        scanf("%d%s",&n,s);
        static int id=0;
        printf("Case %d: ",++id);
        if (s[0]=='A')
            printf("%s\n",n%3==1?"Bob":"Alice");
        else
            printf("%s\n",n%3==0?"Alice":"Bob");
    }
    return(0);
}

