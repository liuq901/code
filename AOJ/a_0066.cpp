#include <cstdio>
char s[20],a[10][10];
bool same(int x,int y,int dx,int dy)
{
    char ch=a[x][y];
    if (ch=='s')
        return(false);
    for (int i=1;i<=3;i++)
    {
        if (a[x][y]!=ch)
            return(false);
        x+=dx,y+=dy;
    }
    return(true);
}
char work()
{
    for (int i=1;i<=3;i++)
    {
        if (same(1,i,1,0))
            return(a[1][i]);
        if (same(i,1,0,1))
            return(a[i][1]);
    }
    if (same(1,1,1,1))
        return(a[1][1]);
    if (same(1,3,1,-1))
        return(a[1][3]);
    return('d');
}
int main()
{
    while (scanf("%s",s)==1)
    {
        for (int i=1;i<=3;i++)
            for (int j=1;j<=3;j++)
                a[i][j]=s[(i-1)*3+j-1];
        printf("%c\n",work());
    }
    return(0);
}

