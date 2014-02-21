#include <cstdio>
char buf[100000];
int main()
{
    for (int i=1;i<=9;i++)
    {
        int x,y;
        scanf("%s%d%d",buf,&x,&y);
        printf("%s %d %d\n",buf,x+y,200*x+300*y);
    }
    return(0);
}

