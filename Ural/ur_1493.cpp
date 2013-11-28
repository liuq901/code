#include <cstdio>
char s[10];
bool check(const char *s)
{
    int a,b;
    a=b=0;
    a=s[0]+s[1]+s[2];
    b=s[3]+s[4]+s[5];
    if (a==b+1 && s[5]!='9' || a+1==b && s[5]!='0')
        return(true);
    return(false);
}
int main()
{
    scanf("%s",s);
    printf("%s\n",check(s)?"Yes":"No");
    return(0);
}

