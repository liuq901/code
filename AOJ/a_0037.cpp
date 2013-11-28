#include <cstdio>
const int c[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
const char b[]="RDLU";
char a[10][10];
bool check(int x,int y,int dir)
{
    switch (dir)
    {
    case 0:
        return(a[2*x-1][y]=='1');
    case 1:
        return(a[2*x][y]=='1');
    case 2:
        return(a[2*x-1][y-1]=='1');
    case 3:
        return(a[2*(x-1)][y]=='1');
    }
}
int main()
{
    for (int i=1;i<=9;i++)
            scanf("%s",a[i]+1);
    int x=1,y=1,dir=0;
    while (1)
    {
        for (int i=-1;i<=2;i++)
        {
            int now=dir+i+4&3;
            if (check(x,y,now))
            {
                dir=now;
                break;
            }
        }
        printf("%c",b[dir]);
        x+=c[dir][0];
        y+=c[dir][1];
        if (x==1 && y==1)
            break;
    }
    printf("\n");
    return(0);
}

