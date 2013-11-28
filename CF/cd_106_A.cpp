#include <cstdio>
const char p[]="6789TJQKA";
char a[10],b[10],c[10];
int main()
{
    scanf("%s%s%s",a,b,c);
    int x,y;
    for (int i=0;i<9;i++)
    {
        if (b[0]==p[i])
            x=i;
        if (c[0]==p[i])
            y=i;
    }
    if (b[1]!=c[1] && b[1]==a[0] || b[1]==c[1] && x>y)
        printf("YES\n");
    else
        printf("NO\n");
    return(0);
}

