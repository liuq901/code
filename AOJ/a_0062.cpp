#include <cstdio>
char s[20];
int a[20][20];
int main()
{
    while (scanf("%s",s)==1)
    {
        for (int i=1;i<=10;i++)
            a[1][i]=s[i-1]-'0';
        for (int i=2;i<=10;i++)
            for (int j=1;j<=11-i;j++)
                a[i][j]=(a[i-1][j]+a[i-1][j+1])%10;
        printf("%d\n",a[10][1]);
    }
    return(0);
}

