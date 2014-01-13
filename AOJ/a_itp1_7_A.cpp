#include <cstdio>
const char *grade(int a,int b,int c)
{
    if (a==-1 || b==-1 || a+b<30)
        return("F");
    if (a+b>=80)
        return("A");
    if (a+b>=65)
        return("B");
    if (a+b>=50)
        return("C");
    return(c>=50?"C":"D");
}
int main()
{
    while (1)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if (a==-1 && b==-1 && c==-1)
            break;
        printf("%c\n",*grade(a,b,c));
    }
    return(0);
}

