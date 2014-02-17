#include <cstdio>
#include <cstring>
char a[10][10];
void work(int pos,int n)
{
    if (n<=4)
        a[2][pos]=' ';
    else
    {
        a[1][pos]=' ';
        n-=5;
    }
    a[3][pos]='=';
    a[4+n][pos]=' ';
}
int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        memset(a,'*',sizeof(a));
        for (int i=5;i;i--)
        {
            work(i,n%10);
            n/=10;
        }
        static bool first=true;
        if (!first)
            printf("\n");
        first=false;
        for (int i=1;i<=8;i++)
        {
            for (int j=1;j<=5;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
    }
    return(0);
}

