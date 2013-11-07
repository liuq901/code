#include <cstdio>
#include <cstring>
char s[100000],t[100000];
int main()
{
    int n;
    scanf("%d",&n);
    int x,y;
    x=y=0;
    for (int i=1;i<=n;i++)
    {
        scanf("%s%s",s,t);
        int p=strcmp(s,t);
        if (p<0)
            y+=3;
        else if (p>0)
            x+=3;
        else
            x++,y++;
    }
    printf("%d %d\n",x,y);
    return(0);
}

