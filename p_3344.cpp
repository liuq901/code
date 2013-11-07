#include <cstdio>
const int c[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
char a[10][10];
bool move(int x0,int y0,int dir)
{
    int x=x0+c[dir][0],y=y0+c[dir][1];
    if (x==0 || x==9 || y==0 || y==9)
        return(false);
    if (a[x][y]!='.')
        move(x,y,dir);
    a[x][y]=a[x0][y0];
    a[x0][y0]='.';
    return(true);
}
inline int turn(int x)
{
    return(x+1&3);
}
int main()
{
    while (1)
    {
        scanf("%s",a[1]+1);
        if (a[1][1]=='-')
            break;
        for (int i=2;i<=8;i++)
            scanf("%s",a[i]+1);
        int x,y,dir;
        for (int i=1;i<=8;i++)
            for (int j=1;j<=8;j++)
                if (a[i][j]=='^')
                    x=i,y=j,dir=0,a[i][j]='.';
                else if (a[i][j]=='>')
                    x=i,y=j,dir=1,a[i][j]='.';
                else if (a[i][j]=='v')
                    x=i,y=j,dir=2,a[i][j]='.';
                else if (a[i][j]=='<')
                    x=i,y=j,dir=3,a[i][j]='.';
        while (1)
        {
            char op[100];
            scanf("%s",op);
            if (op[0]=='#')
                break;
            if (op[0]=='m')
            {
                int n;
                scanf("%d",&n);
                for (int i=1;i<=n;i++)
                {
                    if (!move(x,y,dir))
                        break;
                    x+=c[dir][0],y+=c[dir][1];
                }
            }
            else
            {
                scanf("%s",op);
                if (op[0]=='r')
                    dir=turn(dir);
                else if (op[0]=='b')
                    dir=turn(turn(dir));
                else
                    dir=turn(turn(turn(dir)));
            }
        }
        if (dir==0)
            a[x][y]='^';
        else if (dir==1)
            a[x][y]='>';
        else if (dir==2)
            a[x][y]='v';
        else
            a[x][y]='<';
        for (int i=1;i<=8;i++)
            printf("%s\n",a[i]+1);
        printf("\n");
    }
    return(0);
}

