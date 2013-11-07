#include <cstdio>
char a[10][10],b[10][10];
void turn()
{
    char c[10][10];
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            c[j][4-i+1]=a[i][j];
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            a[i][j]=c[i][j];
}
int main()
{
    for (int i=1;i<=4;i++)
        scanf("%s",a[i]+1);
    for (int i=1;i<=4;i++)
        scanf("%s",b[i]+1);
    char ans[100];
    int t=0;
    for (int T=1;T<=4;T++)
    {
        for (int i=1;i<=4;i++)
            for (int j=1;j<=4;j++)
                if (a[i][j]=='X')
                    ans[t++]=b[i][j];
        turn();
    }
    ans[t]='\0';
    printf("%s\n",ans);
    return(0);
}

