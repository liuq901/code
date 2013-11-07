#include <cstdio>
char s[10000];
int main()
{
    int T;
    scanf("%d",&T);
    int a,b,c;
    a=b=c=0;
    while (T--)
    {
        scanf("%s%*s",s);
        if (s[0]=='E')
            a++;
        else if (s[0]=='M')
            b++;
        else
            c++;
    }
    if (a>b && a>c)
        printf("Emperor Penguin\n");
    else if (b>a && b>c)
        printf("Macaroni Penguin\n");
    else
        printf("Little Penguin\n");
    return(0);
}

