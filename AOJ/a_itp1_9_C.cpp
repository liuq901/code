#include <cstdio>
#include <cstring>
char s[100000],t[100000];
int main()
{
    int Q,a,b;
    a=b=0;
    scanf("%d",&Q);
    while (Q--)
    {
        scanf("%s%s",s,t);
        if (strcmp(s,t)<0)
            b+=3;
        else if (strcmp(s,t)>0)
            a+=3;
        else
            a++,b++;
    }
    printf("%d %d\n",a,b);
    return(0);
}

